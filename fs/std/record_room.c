inherit ROOM;

string record="停止錄音。", record_file="";

void init ()
{
  add_action ("record", "record");
  add_action ("do_say", "say");
}

int record (string arg)
{
  int write_ok;

  if (!wizardp (this_player()))
    return notify_fail (">> 巫師才可錄音！！\n");
  if (!arg) {
    write (">> 要錄音的話，請再命令後面加「檔名」當參數。\n");
    write (">> 現在錄音狀況是："+ record + "\n");
  }
  else if (arg == "stop")
    record = "停止錄音。";
  else {
    seteuid (ROOT_UID);
    arg = resolve_path(this_player()->query("cwd"), arg);
    write (">> "+ this_player()->query("id")+"企圖錄音："+ arg+"\n");
    write_ok = write_file (arg,
        this_player()->query("id")+ " 啟動錄音於："+
        (string)ctime (time()) + "\n", 1);
    if (!write_ok)
      return notify_fail (">> 錄音失敗！！\n");
    else {
      record_file = arg;
      record = "錄音中…";
    }
  }
  return 1;
}

int do_say (string arg)
{
  if (record == "錄音中…")
    write_file (record_file, this_player()->query("id")+"說道："+arg+"\n", 0);
  return 0;
}

