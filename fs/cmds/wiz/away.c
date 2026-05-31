// away.c

inherit SECURITY_D;
inherit F_CLEAN_UP;

int main(object me, string arg)
{
  int	i;

  if (!arg && me->query("away"))
  {
    me->delete("away");
    write("Away 解除．\n");
  }
  else if (!arg)
  {
    me->set("away", 1);
    write("Away 設定．\n"); 
  }
  else {
    me->set("away_msg", arg);
    write("你的 away message 設成 " + arg + "．\n");
    me->set("away", 1);
  }
  return 1;
}

int help(object me)
{
write(@HELP
指令格式 : away <away message>
 
讓別人跟你說話時，看到 away 的訊息，再下一次指令就解除 away 
 
HELP
    );
    return 1;
}
