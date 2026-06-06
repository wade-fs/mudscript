// 段家 書僮  ..made by adam
#include "/open/open.h"
inherit NPC;
void create()
{
        set_name("小書僮",({"boy"}));
        set("gender","男性");
        set("class","scholar");
        set("combat_exp", 1000);
        set("attitude","peaceful");
        set("age",10);
        set("chat_chance", 10);
        set("chat_msg", ({
"小書僮道:  在這裡pray,會有意想不到的事ㄡ!!\n",
        "小書僮道: 好想學『一陽心法秘笈』上的武功喔。\n",
        }));
        set("inquiry", ([
        "thief" : "京城出了盜賊喔, 我怎麼都不知道?",
        "書房" : "王爺在府中有一間祕密書房, 但要找到『暗門』才能進去。",
        "暗門" : "好像是在大廳之中, 但我一直找不到, 王爺說, 等我長大才能帶我去。",
        "一陽心法秘笈"  : "笨!當然是紀載有關一陽心法的事啊, 嘻嘻。",
        ]));
        set("force",150);
        set("max_force",150);
        set("max_kee",300);
        set("kee",300);
        set("force_factor", 1);
        set_skill("force",10);
        set_skill("unarmed",30);
        set_temp("apply/dodge",30);
        setup();
add_money("gold",3);
}

