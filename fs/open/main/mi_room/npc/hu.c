#include <ansi.h>
inherit NPC;

void create()
{
        seteuid(getuid());      // 這行一定要
        set_name("雲中鶴", ({ "badman-hu","hu" }));
        set("attitude","aggressive");
        set("clan_kill",1);
        set("title","四大惡人之末");
        set("nickname",HIR + "窮兇極惡" + NOR);
        set("race", "人類");
        set("gender", "男性");
        set("age", 35);
        set("long", "
一個身形極為瘦長的男人, 一雙眼睛賊兮兮的, 似乎在打什麼壞主意。\n");
        set("str", 30);
        set("cor", 30);
        set("max_kee", 3000);
        set("max_force", 3000);
        set("force", 3000);
        set("force_factor", 15);
        set("combat_exp", 800000);
        set_skill("unarmed", 70);
        set_skill("parry", 70);
        set_skill("dodge", 120);
        set_skill("force", 50);
        set_skill("snowforce",80);
        set_skill("hell-evil",90);
        set_skill("sha-steps", 120);
        map_skill("unarmed","hell-evil");
        map_skill("dodge","sha-steps");
        map_skill("force","snowforce");
        set("chat_chance", 8);
        set("chat_chance_combat",20);
        set("chat_msg_combat",({
        (: this_object(),"special_attack" :),
        }));
        set_temp("apply/armor", 70);

        setup();
        add_money("silver", 10);
        carry_object("/open/tailong/obj/ghost-claw")->wield();
}


 int special_attack()
 {
   object ob,me;
   int k;
   me = this_object();
   k = random(10);
   ob=this_object()->query_enemy();
   if(k > 7)
   {
   message_vision(HIB + "
\n雲中鶴身形越轉越快, 激起一陣陣的旋風, 只見狂風中四有無數鬼爪向你攻來, \n
此正是邪派終極殺招\n\n"
HIR + "\t～～" + HIG + "『狂風煉獄爪』" + HIR + "～～\n\n" + NOR,this_object());
  ob->add("kee",200);
   }
   else
   {
   message_vision(HIY + "\n雲中鶴運起『天魔療傷心法』不可思議的光芒從雲中鶴身上發出，雲中鶴的創傷恢復了!\n" + NOR,this_object());
me->add("kee",500);
me->add("max_kee",100);
   }
  return 1;
  }
void die()
{
   object winner;
   winner= query_temp("last_damage_from");
   tell_object(winner,
HIY + "你正在喘息之際, 突然腳下一空, 掉入了一個深洞之中..\n" + NOR);
   winner->move("/open/main/mi_room/mi08.c");
        ::die();
        return 0;
}
