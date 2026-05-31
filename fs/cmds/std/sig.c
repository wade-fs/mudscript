// sig.c
//
// 由 wade 新增, 可以配合 post/followup 等命令的使用
// by wade in 6/30/1996

inherit F_CLEAN_UP;
inherit F_DBASE;

void create()
{
        seteuid (getuid());
        set ("名字", "簽名檔指令");
        set ("id", "sig");
}

int main(object me, string arg)
{
  string 	id, fn, *buf;

  if (me != previous_object()) return 0;

  id = me->query("id");
  fn = sprintf ("%s/sig/%s/%s.sig", DATA_DIR, id[0..0], id);
  assure_file (fn);

  if (arg == "none")
  {
    rm (fn);
    write("清除簽名檔。\n");
  }
  else {
    me->edit( (: this_object(), ({ "do_plan", this_player()}) :) );
  }
  return 1;
}

void do_plan(object me, string text)
{
  string fn, id;
  object link_ob;

  id = me->query("id");
  fn = sprintf ("%s/sig/%s/%s.sig", DATA_DIR, id[0..0], id);

  if (write_file (fn, text, 1) == 1)
    write ("簽名檔設定完成。\n");
  else
    write ("簽名檔無法寫入.\n");
}

int help(object me)
{
write(@HELP
指令格式 : sig || sig none
指令說明 :
	   這個指令可以編輯自己的簽名檔，sig none 可以清除設定。
	   注意: 沒加參數的話會在你編完簽名檔之後蓋掉舊的檔案.

相關指令 : plan，post，followup
HELP
    );
    return 1;
}

