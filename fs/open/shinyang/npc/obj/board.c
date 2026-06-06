// torch

inherit ITEM;
string query_long();

void create()
{
        set_name("告示牌", ({ "board", }) );
        set("unit", "件");
       set("value", 100);
       set("long",(: query_long:));
       set("no_get",1);
       set("no_sac",1);
	setup();
}
string query_long()
{
  object *users;
  string str = "告示牌上面寫道：
╭–––––––––––––––––––––––––––––╮
∣    近期內因為蒙古大軍來襲，但因城內軍士兵人數不足，在此徵∣ 
∣招武林人士來協助扺抗蒙古大軍，意者請向大將軍狂亂月報名。  ∣
∣                                                          ∣\n";
users = environment(this_object())->get_users();
if(!sizeof(users)) 
  str += sprintf("∣    目前沒有任何的報名者                                  ∣\n");
else
{
  int i = 1;
  str += sprintf("∣ %-20s                                     ∣\n","報名者：");

  foreach(object user in users)
  {
    str += sprintf("∣  [%2d] %-50s ∣\n",i,user->short());
    i++;

  }
}
  str += "∣                                                          ∣
∣                                       將軍    狂亂月書   ∣
╰–––––––––––––––––––––––––––––╯\n";
return str;
}
