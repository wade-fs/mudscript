// 大寫的檔 --> 小寫的檔名
// by wade@Fantasy.Space 8/22/87

inherit F_CLEAN_UP;

int main(object me, string arg)
{
  int n, i;
  string dir, cmds;
  mixed *file;

  dir = resolve_path(me->query("cwd"), arg);
  if (file_size(dir) == -2 && dir[strlen(dir)-1] != '/') dir += "/";
  file = get_dir(dir, -1);
  if (!sizeof(file)) {
    if (file_size(dir) == -2) return notify_fail("目錄是空的。\n");
    else
      return notify_fail("沒有這個目錄。\n");
  }

  n = sizeof(file);
  for (i=0; i<n; i++) {
    int         j, len;
    string      fn="xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";

    cmds = "mv " + file[i][0];
    fn = file[i][0];

    len = strlen (file[i][0]);
    for (j=0; j<len; j++) {
      if (file[i][0][j] <= 'Z' && file[i][0][j] >= 'A')
        fn[j] = file[i][0][j] + ('a' - 'A');
    }
    cmds += " " + fn;
    if (fn != file[i][0])
      this_player()->do_command (cmds);
  }

  return 1;
}

int help(object me)
{
        write(@HELP
指令格式: b2s

  話說 8/22/87, wataru 要麵包幫他把 ftp 成「大寫」的檔（幾十個）
全改成小寫的，他要麵包先傳回去，改成小寫檔名再傳回來，…
這好像在考驗麵包的耐性一樣…
  自從那天後，就有這個命令了。
  本指令會轉換所有目錄下的檔案名寫，大寫變小寫

                wade@Fantasy.Space 8/22/87
HELP
        );
        return 1;
}
