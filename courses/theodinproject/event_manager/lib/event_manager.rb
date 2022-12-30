require "csv"
require "google/apis/civicinfo_v2"
require "erb"
require "time"
require "date"

def clean_zipcode(zipcode)
  zipcode.to_s.rjust(5, "0")[0..4]
end

def clean_homephone(home_phone)
  format_phone = home_phone.gsub(/\D/, "")
  return "" if format_phone.size < 10 || format_phone.size > 11 || (format_phone[0] != "1" && format_phone.size > 11)
  return format_phone[1..] if format_phone.size == 11 && format_phone[0] = "1"
  format_phone
end

def legislators_by_zipcode(zipcode)
  civic_info = Google::Apis::CivicinfoV2::CivicInfoService.new
  civic_info.key = 'AIzaSyClRzDqDh5MsXwnCWi0kOiiBivP6JsSyBw'

  begin
    legislators = civic_info.representative_info_by_address(
      address: zipcode, 
      levels: 'country', 
      roles: ['legislatorUpperBody', 'legislatorLowerBody']
    ).officials
  rescue
    'You can find your representatives by visiting www.commoncause.org/take-action/find-elected-officials'
  end
end

def save_thank_you_letter(id, form_letter)
  Dir.mkdir "output" unless Dir.exist? "output"
  filename = "output/thanks_#{id}.html"
  File.open(filename, "w") { |file| file.write form_letter }
end

contents = CSV.open(
  "event_attendees.csv", 
  headers: true,
  header_converters: :symbol
)

template_letter = File.read("form_letter.html")
erb_template = ERB.new template_letter

hours = []
wkdays = []
contents.each do |row|
  id          = row[0]
  name        = row[:first_name]
  date        = row[:regdate].split(" ")
  home_number = clean_homephone(row[:homephone])
  zipcode     = clean_zipcode(row[:zipcode])
  legislators = legislators_by_zipcode(zipcode)

  hours << Time.parse(date[1]).hour
  wkdays << Date.strptime(date[0], "%m/%d/%Y").wday

  form_letter = erb_template.result(binding)

  save_thank_you_letter(id, form_letter)
end

avg_wkdays = wkdays.tally
avg_hours = hours.tally
p avg_hours
p avg_wkdays


