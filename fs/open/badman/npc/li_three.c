#include "/open/open.h"
inherit NPC;
void do_sword_book();
void create()
{
        set_name("李三", ({ "li three","li","three" }) );
        set("family/family_name","惡人谷");
        set("class","bandit");
        set("gender", "男性" );
        set("age", 38);
        set("long",
"一臉賊頭賊腦的樣子，見你走來忙將某物
藏於身後，見他腰間佩帶著一把名劍，看
來是把寶劍喔，忍不住想問他一問。\n");
        set("combat_exp",2500000);
        set("max_kee",7500);
        set("kee",7500);
        set("max_sen",1500);
        set("sen",1500);
        set("max_gin",1500);
        set("gin",1500); 
        set("max_force",3000);
        set("force",6000);
        set("force_factor",10);
        set("bellicosity",3000);
        set("title","妙手空空 ");
        set_skill("parry",100);
        set_skill("dodge",100);
        set_skill("sword",100);
        set_skill("badsword",100);
        set_skill("ghost-steps",100);
        set_skill("force",120);
        set_skill("badforce",200);
        map_skill("dodge","ghost-steps");
        map_skill("force","badforce");
        map_skill("sword","badsword");
        map_skill("parry","badsword");
        set_temp("apply/attack",20);
        set_temp("apply/armor",20);
        set_temp("apply/dodge",20); 
        set("inquiry",([
"寶劍" : "這是我從江南四俠處偷來的，可是很有價值呢！",
"偷來" : "呵～我偷的技術可是很高明的喔，也因此才會被人追殺而躲入谷內",
"追殺" : "哼！等我練成一項武學後，就是我出谷時了！",
"武學" : "怎可跟你透露呢，我要練功\了，滾吧～",
"魔日劍法" : "魔日劍法？那不是秦雲的拿手絕技嗎？你怎會問我這問題呢？",
"魔日劍譜" : (: do_sword_book :),
]));
        setup();
        carry_object("/open/gsword/obj/sword.c")->wield();
        carry_object("/u/k/know/plan/sword.c");
        carry_object("/u/k/know/plan/book.c");
}
void do_sword_book()
{
object me=this_player();
if(me->query("class") != "bandit") {
command("say 幹.....................嘛，又不關你的事！\n");
return ;
}
command("think "+me->query("id"));
command("say 既然你已查到我頭上來了，休怪我無情了！");
command("kill "+me->query("id"));
}
int accept_kill(object who)
{   
    command("say 納命來吧！");
    command("wield all");
    return 1;
}
void die()
{
   object me;
   me= this_object()->query_temp("last_damage_from");
   if( me&& userp(me) ) 
   {
new("/open/badman/obj/book.c")->move(this_object());
   me->set_temp("get_badsword_book",1);
   }
   ::die() ;
}
