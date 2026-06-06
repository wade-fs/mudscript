#include "/open/open.h"
#include <ansi.h>
#include "marksman.h"
int do_list();
inherit F_VENDOR;
void create()
{
        set_name("張三", ({ "chang sen","chang","sen" }) );
        set("gender", "男性" );
        set("age", 45);
        set("long", @LONG
他是長沙城裏最有名的鐵匠，你可以問問他有在賣些什麼(list)。
LONG);
        set("title",HIR"金身火煉"NOR);
        set("attitude", "friendly");
        set("combat_exp",50000);
        set_skill("archery",40);
        set_skill("parry",40);
        set_skill("dodge",40);
        set("greeting_msg", ({
        "張三說: 這位人士你有什麼一些弓箭來防身嗎?\n",
        "張三叫道: 你有什麼都東西要我為你打造的嗎!!\n",
        }) );
        set("list",([
        "come": ([
                 "local":"/open/marksman/obj/come",
                 "id":"come",
                ]),
        "sparrow arrow": ([
                "local":"/open/marksman/obj/arrow-2",
                "id":"sparrow arrow",
                ]),
        "violet arrow": ([
                "local":"/open/marksman/obj/arrow-3",
                "id":"violet arrow",
                ]),
        "red arrow":([
                "local":"/open/marksman/obj/arrow-4",
                "id":"red arrow",
                ]),
        "steel bow":([
                "local":"/open/marksman/obj/bow-2",
                "id":"steel bow",
                ]),
        "paint bow": ([
                "local":"/open/marksman/obj/bow-3",
                "id":"paint bow",
                ]),
        "force bow": ([
                "local":"/open/marksman/obj/bow-4",
                "id":"force bow",
                ]),
]));
        setup();
carry_object(C_OBJ"/arrow-1");
carry_object(C_OBJ"/bow-1")->wield();
}
int accept_kill(object ob)
{
 command("say 哼!連我你也敢殺，你受死吧");
 command("holdwith arrow");
 command("kill"+ob->query("id"));
return 1;
}
int accept_fight(object ob)
{
command("say 你沒有看見我在忙嗎？不要買東西就快走吧!");
return 0;
}
void init()
{
           add_action("do_list","view");
        add_action("do_want","want");
}
int do_list()
{
return notify_fail("
本店所供給之武器：

一袋瓊雀箭(Sparrow arrow)  
一袋紫邪箭(Violet arrow)   
一袋朱雀箭(Red arrow)      
玄鐵弓(Steel bow)            
黑漆弓(Paint bow)             
玄武弓(Force bow) 
哨子  (come)

有須要武器者請 want xxxx\n");
}

int do_want(string weapon)
{
        object ob;
        if(this_player()->query("class")!="marksman")
        {
                command("say 這裡的武器只有本派能拿。\n");
                return 1;
        }
        if(!query("list/"+weapon))
        {
                command("say 你想要什麼武器？\n");
                return 1;
        }
        if(present(query("list/"+weapon+"/id"),this_player()))
        {
                command("say 武器用完再來拿。\n");
                return 1;
        }
        ob=new(query("list/"+weapon+"/local"));
        ob->move(this_player());
message_vision("$N拿給$n所要的"+ob->name()+"。\n",this_object(),this_player());
                return 1;
}
