#include <weapon.h>
#include <ansi.h>

inherit SWORD;
object user;
object ob;
void create()
{
   
   seteuid(geteuid());
   set_name("擎天神劍",({"Heaven sword","sword"}));
   set_weight(5000);
   set("value",10000);
   if( clonep() )
        set_default_object(__FILE__);
   else {
        set("unit","把");
   set("long","\n一把普普通通的劍柄。\n");
   set("material", "blacksteel");
   set("weapon_prop/sword", 10);
   set("wield_msg","$N將內力注入$n中，一道劍芒由劍柄射出。\n");
   set("unwield_msg", "$N停止灌輸內力，$n的劍刃頓時消失。\n");
   init_sword(95);
      }
   setup();
}   
void init()
{
  add_action("do_wield","wield");
}

void do_wield(string str)
{
  ::wield();
    user=this_player();
    ob=this_object();
    user->add("force",-100);
    write((string)user->query("name")+"將內力注入"+(string)ob->query("name")+"中，一道劍芒由劍柄射出。\n");
}
