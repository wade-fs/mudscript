// wade 2002-10-23 加入 secure 可以 autoload 三件物品
inherit F_CLEAN_UP;
int help (object me);
 
int check( object obj )
{
        if( obj->query("no_sec") )
                return notify_fail( "此物品被設定為無法保護。\n" );
        return 1;
}
int main(object me,string arg)
{
  object        *ob, obj;
  int           i, n;

  int		autoload;
 
  if (!arg) return help(me);

  ob = all_inventory(me);
  n = sizeof (ob);

  autoload=0;

  if (arg == "all") {
    for (i=0; i<n; i++) {
      ob[i]->set_temp("secured", 1);
      if (ob[i]->query("equipped")) {
        if (autoload < 3 && !ob[i]->query_autoload()) {
          ob[i]->set("autoload", 1);
          autoload++;
        }
      }
    }
  }
 
  else if (obj = present(arg, me)) {
    if (autoload < 3 && obj->query("equipped") && !obj->query_temp ("secured"))
      obj->set ("autoload", 1);

    obj->set_temp("secured",1);
  }
  else return notify_fail ("沒有這樣物品。\n");
  return 1;
}
 
int help(object me)
{
        write(@HELP
指令格式 : secure <物件>
範    例 : secure map
           secure all
說    明 :
           本指令讓玩家可以保護物件，以免被 drop，sell，give
HELP
    );
    return 1;
}
