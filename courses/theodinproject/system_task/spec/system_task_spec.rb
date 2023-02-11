require "./lib/system_task"

describe SystemTask do
  it "executes tasks" do
    io = StringIO.new
    st = SystemTask.new(io)

    st.execute
    io.rewind
    expect(io.read).to eq "preparing to execute\nstarting first task\nstarting second task\nexecution complete\n"
  end

  it "execute tasks in /dev/null" do
    io = File.open(File::NULL, "w")
    st = SystemTask.new(io)

    st.execute

    expect(io.write).not_to be == ""
  end

end
