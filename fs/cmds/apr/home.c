// home.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
  string msg;
  string home_path;
  object env;

  if ( file_size(home_path=user_path(geteuid(me)) + "workroom.c") <= 0 )
    if (file_size(home_path=user_path(geteuid(me)) + "room/workroom.c") <=0 )
      return notify_fail("你沒有自己的工作室。\n");
  if( stringp(msg = me->query("msg_mout")) )
    message_vision(msg, me);
  else
    message_vision("只見一陣煙霧過後﹐$N的身影已經不見了。\n", me);

  env = environment(me);
  me->move(home_path);
  if( !sizeof(all_inventory(env)) && ( !env->query("objects")
   || !sizeof(env->query("objects")) ) ) destruct(env);

  if( stringp(msg = me->query("msg_min")) )
    message_vision(msg, me);
  else
    message_vision("$N的身影突然出現在一陣煙霧之中。\n", me);

  return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : home

利用此一指令可直接回到自己的工作室。
如果你有設定 'msg_home' property, 則在場的人都會看到那個訊息.
HELP
    );
    return 1;
}
