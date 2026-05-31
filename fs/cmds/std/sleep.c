// sleep.c
// 冬眠，避免玩家玩太久，自己設冬眠時間
// by wade@Fantasy.Space 87/8/11

inherit F_CLEAN_UP;


int main ( object me, string arg )
{
  int t=0, d=0, h=0, m=0, s=0;

  if (!arg || arg == "") {
    return 0;
  }

  sscanf (arg, "%d %d %d %d", s, m, h, d);
  if (d < 0 || h < 0 || m < 0 || s < 0) {
    write ("時間一定要大於○\n");
    return 1;
  }
  t = ((d * 24 + h) * 60 + m) * 60 + s;

  t += time();
  me->set("sleep",t);
  printf ("冬眠時間為：%d天%d小時%d分%d秒。\n設定冬眠到 %s\n",
        d, h, m, s, ctime (t));
  me->do_command ("quit");
  return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : sleep 秒 分 時 天
指令說明 :
           這個指令讓使用者設定一段時間內不能上線。
           天/時/分/秒，不可以小於○，當然，可以省略不給
           當你想一段時間不上線，又怕意志力不夠，
           用這命令就對了。

   ** : 此命令會強迫你 "quit" :)
HELP
    );
    return 1;
}
