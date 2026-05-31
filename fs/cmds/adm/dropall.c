// drop.c
 
inherit F_CLEAN_UP;
 
int do_drop(object me, object obj);
 
int main(object me, string arg)
{
  int i;
  object obj, *inv;
 
  seteuid (getuid());
  if (!arg) obj = me;
  else {
    arg = lower_case (arg);
    obj = find_player (arg);
  }
 
  inv = all_inventory (me);
  for (i=0; i<sizeof(inv); i++) {
    destruct (inv[i]);
  }
  if (arg)
    write ("你丟棄身上 ("+arg+") 所有東西完畢.\n");
  else
    write ("你丟棄身上所有東西完畢.\n");

  return 1;
}
 
int help(object me)
{
  write(@HELP
指令格式 : drop <物品名稱>
 
這個指令可以讓你丟下你所攜帶的物品.
 
HELP
    );
    return 1;
}
