int help (object me);
inherit F_CLEAN_UP;

int main(object me, string arg)
{
  object	*ob, obj;
  int		i;

  if (!arg) return help(me);
  if (arg == "all") {
    for (i=0; i<sizeof(ob=all_inventory(me)); i++) {
      ob[i]->delete_temp("secured");
      ob[i]->delete("autoload");
    }
  }

  else if (obj = present(arg, me)) {
    obj->delete_temp("secured");
    obj->delete ("autoload");
  }
  else return notify_fail ("沒有這樣物品.\n");
  return 1;
}
 
int help(object me)
{
	write(@HELP
指令格式 : unsecure <物件>
範    例 : unsecure map
	   unsecure all
說    明 :
	   本指令讓玩家可以取消保護物件，才可以被 drop，sell，give
HELP
    );
    return 1;
}
