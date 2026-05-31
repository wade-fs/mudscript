#include <ansi.h>
#include <armor.h>
inherit NECK;
void create()
{
  set_name(HIW"魔斬冥輪"NOR,({"six-hurt neck","neck"}));
  set_weight(100);
  if( clonep() )
  set_default_object(__FILE__);
  else {
  set("long","傳說中魔神的項鍊，有能連續攻擊之效能，但卻會嗜其使用者之血氣。\n");
  set("unit", "條");
  set("material","steal");
  set("no_auc",1);
  set("no_sell",1);
  set("no_put",1);
  set("no_drop",1);
  set("no_give",1);  
  set("no_steal",1);
  set("no_save",1);
  set("armor_prop/armor", 10);
  }
  setup();
}
void init()
{
        if( this_player()==environment() )
        add_action("do_wear","wear");
        add_action("do_remove","remove");
}
int do_wear(string str)
{
     object user;
     user = this_player();
     if( str == "neck" || str == "six-hurt neck" || str == "all"  )
     {
       if(user->query_temp("six-hurt"))
       {
       message_vision(HIC"$N戴上了魔斬冥輪，一股力量由然而生。\n"NOR,user);
       }else{
       ::wear();
         if( query("equipped") )
         {
         message_vision(HIC"$N戴上了魔斬冥輪，一股力量由然而生。\n"NOR,user);
         user->add("max_kee",-500);
         user->add("eff_kee",-500);    
         user->add("kee",-500); 
         user->set_temp("six-hurt",1);
         }
       }
     }
}

int do_remove(string str)
{
     object user;
      user = this_player();
     if(str=="six-hurt neck" || str=="neck" || str=="all" )
     if( query("equipped") )
     {
if(user->query_temp("six-hurt")) {
      message_vision(HIY"$N卸下魔斬冥輪後，所衍生的力量頓時消失無影。\n"NOR,user);
      user->add("max_kee",500);
      user->delete_temp("six-hurt");
     }
}
}
