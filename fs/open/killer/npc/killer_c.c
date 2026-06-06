#include <ansi.h>
inherit NPC;
void create()
{
    set_name("二級殺手教頭",({"trainer"}) );
    set("long",
   "黑牙聯的實戰教練,專門與來此練習的人對招，不管各門各派\n");
    set("race", "人類");
    set("gender","男性");
     set("combat_exp",50000);
    set("age",40);
    set("title","黑牙聯成員");
    set("kee",300);
    set("max_kee",300);
    set("bellicosity",350);
    set_skill("sword",55);
    set_skill("dodge",45);
    set_skill("parry",45);
    set_skill("shadow-kill",35);
    map_skill("sword","shadow-kill"); 
    set("chat_chance", 3);
    set("chat_msg", ({ (: this_object(), "random_move" :),
    "教頭憤怒地說: 小子,別偷懶 !\n",
 }));
    setup();
   carry_object("/open/gsword/obj/woodsword")->wield();
   add_money("silver",45);
}
