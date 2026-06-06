#include <ansi.h>
inherit NPC;
mapping *action = ({
([ "action" : "$N使出絕情神掌第一招"+HIY+"【亢龍有悔】"+NOR+"，右掌劃了個圈圓，向$n的$l推去",
                "dodge"      :    -25,
                "parry"      :    -20,                                      
                "damage"     :    100,
                "damage_type":   "瘀傷",
           ]),
([ "action" : "$N使出絕情神掌第二招"+HIG+"【飛龍在天】"+NOR+"，猶如飛龍般躍起半空，居高下擊，向$n
的$l擊出",
                "dodge"      :     -50,
                "parry"      :     -10,
                "damage"     :     110,
                "damage_type":   "瘀傷",
           ]),
([ "action" : "$N使出絕情神掌第三招"+HIR+"【突如其來】"+NOR+"，於迅雷不及掩耳的速度，讓$n攻其不備",
                "dodge"      :    -30,
                "parry"      :    -45,
                "damage"     :    130,
                "damage_type":   "瘀傷",
            ]),
([ "action" : "$N使出絕情神掌第四招"+HIB+"【雙龍取水】"+NOR+"，左右分使絕情神掌，令$n無法敵擋，內
外皆受到極大的傷害", 
                "dodge"      :   -50,
                "parry"      :   -50,
                "damage"     :   150,
                "damage_type":   "瘀傷",
            ]),
   });


void create()
{
  set_name("絕情門弟子", ({ "trainee" }) );
  set("long","他在這個廣場操練中，看來很強壯，不好對付的樣子。\n");
  set("race", "人類");
  set("gender","男性");
  set("combat_exp",400000);
  set("age",18);
  set("cor",30);
  set("cps",30);
  set("str",20);
  set("kee",1000);
  set("max_kee",1000);
  set("force",700);
  set("max_force",700);
  set("force_factor",2);
  set("chat_chance",25);
  set("bellicosity",1000);
  set("attitude","aggressive");
  set_skill("dodge", 40);
  set_skill("linpo-steps",40);
  set_skill("force",40);
  set_skill("unarmed", 60);

  map_skill("dodge","linpo-steps");
  set("chat_chance_combat", 25);
  set_temp("apply/armor",40);
  set_temp("apply/damage",20);
  set("chat_msg", ({
       (: this_object(),"random_move" :),
  }) );
  setup();
  set("default_actions", (: call_other, __FILE__,"query_action" :));
  add_money("coin",100);

  reset_action();
}
mapping query_action()
{
        return action[random(sizeof(action))];
}
