#include <ansi.h>
#include "/open/open.h"
inherit NPC;
string answer_head()
 {
 int head;
 head=this_player()->query("snow-head",1);
return sprintf("你一共殺了%d個雪蒼弟子。",head);
 }
int head=this_player()->query("snow-head",1);
void create()
{
        set_name("莫歡愁",({"older man","man"}));
        set("long","他是專門兌換雪蒼人頭的莫家總管。\n");
        set("gender","男性");
        set("title","莫家總管");
        set("combat_exp",100);
        set("attitude","friendly");
        set("age",60);
        set("str",40);
        set("cor", 24);
        set("cps", 18);
        set("per", 24);
        set("int", 42);
        set("force",40);
        set("inquiry",([
        "head":(: answer_head :)
        ]));
        set("list",([
        "雪蓮丹": ([
                "local":"/open/gsword/obj/ff_pill",
                "head":2,
                "amount":500,
                "id":"force pill",
                ]),
        "靈芝仙丹": ([
                "local":"/open/gsword/obj/f_pill",
                "head":2,
                "amount":500,
                "id":"super pill",
                ]),
        "冰心露":([
                "local":"/daemon/class/doctor/medicine/curesick",
                "head":2,
                "amount": 500,
                "id":"ice heart pill",
                ]),
        "百花清心露":([
                "local":"/open/ping/obj/poison_pill",
                "head":2,
                "amount": 500,
                "id":"flower pill",
                ]),
        "日輪碎星破": ([
                "local":"/daemon/class/fighter/star",
                "head":30,
                "amount":30,
                "id":"destoryer",
                ]),
        "金剛指環": ([
                "local":"/open/snow/obj/figring",
                "head":35,
                "amount":35,
                "id":"figring",
                ]),
        "紅寶石戒指":([
                "local":"/open/gsword/obj/ring-1",
                "head":20,
                "amount": 20,
                "id":"ruby_ring",
                ]),
        "冰雪神戒":([
                "local":"/open/ping/obj/ring-2",
                "head":20,
                "amount": 20,
                "id":"ice_ring",
                ]),
        "邪雲神扇": ([
                "local":"/open/ping/obj/fan-1",
                "head":20,
                "amount":20,
                "id":"evil_fan",
                ]),
        "飄雲扇": ([
                "local":"/open/ping/obj/cloud_fan",
                "head":35,
                "amount":35,
                "id":"cloud fan",
                ]),
        "厚背紫金刀":([
                "local":"/daemon/class/blademan/obj/gold-blade",
                "head":50,
                "amount": 50,
                "id":"gold blade",
                ]),
        "賞金":([
                "local":"/obj/money/gold",
                "head":1,
                "amount": 5000,
                "id":"gold",
                ]),
]));

        setup();
}

void init()
{
        add_action("do_list","list");
        add_action("do_want","want");
}
int do_list(object me)
{
        string *name;
        int i;
        me=this_player();
        name = keys(query("list"));
        tell_object(this_player(),"目前所能換到的獎品: \n\n");
        tell_object(this_player(),"  ｛ 獎品 ｝｛ 所須人頭數 ｝\n\n");
        for(i=0;i<sizeof(name);i++)
tell_object(this_player(),sprintf("%10s%10d\n",name[i],query("list/"+name[i]+"/head")));
        return 1;
}

int do_want(string weapon)
{
        object ob;
        if(this_player()->query("snow-head")<5)
            {
        command("say 想要賞賜就多殺一點敵人呀！\n");
                return 1;
        }
        if(!query("list/"+weapon))
        {
                command("say 你想要什麼賞賜？\n");
                return 1;
        }
        if(query("list/"+weapon+"/amount")<=0)
        {
                command("say 這樣東西現在缺貨。\n");
                return 1;
        }
if(this_player()->query("snow-head") < query("list/"+weapon+"/head"))
{
    command("say 等你人頭夠了再來換吧！\n");
      return 1;
  }
if(weapon=="雪蓮丹"||weapon=="靈芝仙丹"||weapon=="冰心露")
{
        ob=new(query("list/"+weapon+"/local"));
        ob->add_amount(15);
        add("list/"+weapon+"/amount",-1);
this_player()->add("snow-head",-query("list/"+weapon+"/head"));
        ob->move(this_player());
        ob->set("no_drop",1);
        ob->set("no_give",1);
message_vision("$N拿給$n所要的"+ob->name()+"。\n",this_object(),this_player());
                return 1;
}
        ob=new(query("list/"+weapon+"/local"));
        ob->add_amount(1);
        add("list/"+weapon+"/amount",-1);
this_player()->add("snow-head",-query("list/"+weapon+"/head"));
        ob->move(this_player());
        ob->set("no_drop",1);
        ob->set("no_give",1);
message_vision("$N拿給$n所要的"+ob->name()+"。\n",this_object(),this_player());
                return 1;
}
