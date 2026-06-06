#include <ansi.h>
#include "/open/open.h"
inherit NPC;
string do_help();
string answer_war_score()
{
 int war_score;
war_score=this_player()->query("war_score",1);
         return sprintf("你共有%d點戰功\點數。\n",war_score);
}
int war_score;
void create()
{
        object ob;
         set_name("李  喚",({"officer lee","officer","lee"}));
        set("long","他是專門給護國有功\的戰士授與獎勵,你可以用list 跟convert 換取。 \n");
        set("gebder","男性");
         set("nickname",HIC + "首席戰情官" + NOR);
        set("combat_exp",100);
          set("inquiry",([
             "戰功\":(: answer_war_score :),
             "幫忙" : (: do_help :),
        ]));
          set("list",([
/*        "雪蓮丹": ([
                "local":"/open/gsword/obj/ff_pill",
                "war_score":10,
                "amount":500,
                "id":"force pill",
                       ]),
          "靈芝仙丹": ([
                  "local":"/open/gsword/obj/f_pill",
                  "war_score":15,
                  "amount":500,
                  "id":"super pill",
                        ]),
*/           "血影摧心": ([
                    "local":"/open/main/obj/unarmed-b",
                    "war_score":1200,
                    "amount":1,
                    "id":"blood figring",
                           ]),
          "火鳥脛甲": ([
                  "local":"/open/main/obj/bird_legging",
                  "war_score":500,
                  "amount":10,
                  "id":"fire bird leggings",
                         ]),
/*          "赤麟肩甲": ([
                  "local":"/open/main/obj/armband",
                  "amount":8,
                    "war_score":30,
                  "id":"red chilin armband",
                         ]),
*/            "金蠶手套": ([
                    "local":"/open/main/obj/g_glove",
                    "amount":5,
                    "war_score":1000,
                   "id":"gold gloves",
                          ]),
            "閻月披風": ([
                    "local":"/open/main/obj/m_cloak",
                    "amount":3,
                    "war_score":1500,
                   "id":"dark moon cloak",
                          ]),
/*            "聖靈戰甲": ([
                    "local":"/open/main/obj/plate",
                    "amount":1,
                    "war_score":100,
                   "id":"holy ghost plate",
                          ]),
*/            "青龍偃月刀": ([
                    "local":"/open/main/obj/dragon-moon",
                    "amount":1,
                    "war_score":1500,
                   "id":"green dragon blade",
                          ]),
            "留香扇": ([
                    "local":"/open/main/obj/present-f",
                    "amount":1,
                    "war_score":1500,
                    "id":"ancient fan",
                          ]),
			"銀鷹頭盔": ([
                    "local":"/autoload/open-area/shawk",
                    "amount":1,
                    "war_score":5000,
                    "id":"silver-hawk",
                          ]),
]));
        setup();
}
int accept_object(object me,object ob)
{
        string letter_id;
        letter_id=ob->query("id");
        if(letter_id=="lee_letter")
        {
                destruct(ob);
                command("say 咦!我的信，嗯......多謝你啦");
                command("bow"+me->query("id"));
                me->add("taigan_exp",10);
                me->delete_temp("working");
                switch(random(3)){
                        case 1:
                        me->set("taigan_work",8);
                        break;
                        case 2:
                        me->set("taigan_work",1);
                        break;
                        case 3:
                        me->set("taigan_work",2);
                        break;
                        }
        }
        else{
                command("say 嗯???這信不是給我的，你搞錯囉!!!");
                command("give"+ob->query("id")+me->query("id"));
            }
}
string do_help()
{
        int work,i,j,k;
        object me,ob,letter;
        me=this_player();
        ob=this_object();
        work=me->query("taigan_work");
        if(work!=7 || me->query_temp("working") ||me->query("class")!="taigan")
                return "我現在沒什麼事需要你幫忙，去看看別人需不需要吧。\n";
        else
        {
        switch(random(3))
        {
                case 1:
                new("/open/capital/room/sroom/obj/wu_letter")->move(me);
                me->set_temp("working",1);
                message_vision("給了$N一封信。\n",me);
                return "你來的正好，我這裡有封信要交給糧草總兵吳大人，你幫我跑一趟吧。\n";
                break;
                case 2:
                new("/open/capital/room/sroom/obj/yen_letter")->move(me);
                me->set_temp("working",1);
                message_vision("給了$N一封信。\n",me);
                return "你來的正好，我這裡有封信要交給東廠的嚴公公，你幫我跑一趟吧。\n";
                break;
                case 3:
                new("/open/capital/room/sroom/obj/chang_letter")->move(me);
                me->set_temp("working",1);
                message_vision("給了$N一封信。\n",me);
                return "你來的正好，我這裡有封信要交給東廠的張公公，你幫我跑一趟吧。\n";
                break;
        }
        }
}
void init()
{
        add_action("do_list","list");
        add_action("do_convert","convert");
}
int do_list(object me)
{
        string *name;
        int i;

        me=this_player();
        name = keys(query("list"));
        tell_object(this_player(),"目前所能換到的獎: \n");
    tell_object(this_player()," ｛ 獎品 ｝ ｛ 所須戰功\點數 ｝\n");
        for(i=0;i<sizeof(name);i++)
tell_object(this_player(),sprintf("%10s%10d\n",name[i],query("list/"+name[i]+"/war_score")));
        return 1;
}
int do_convert(string weapon)
{
        object ob;
        if(this_player()->query("war_score")<=10)
{
          command("say 沒功\勞要啥獎，早點回去睡吧!\n");
                return 1;
}
        if(!query("list/"+weapon))
        {
                command("say 你想要什麼賞賜?\n");
                return 1;
        }
        if(query("list/"+weapon+"/amount")<=0)
{
                command("say 這樣東西現在缺貨。\n");
                return 1;
}
 if (this_player()->query("war_score") < query("list/"+weapon+"/war_score") ) {
    sprintf("你共有%d點護國戰功\點數。\n", war_score);
    command("say 等你戰功\足夠再來換吧！\n");
      return 1;
}
        ob=new(query("list/"+weapon+"/local"));
        ob->add_amount(1);
        add("list/"+weapon+"/amount",-1);
        this_player()->add("war_score",-query("list/"+weapon+"/war_score"));
            ob->move(this_player());
        ob->set("no_drop",1);
        ob->set("no_give",1);
        message_vision( "$N拿給$n所要的"+ob->name()+"\n",this_object(),this_player());
		write_file("/log/war/convert",sprintf("%s(%s) 用戰功\換%s於 %s\n",
		this_player()->name(1),this_player()->query("id"),ob->name(),ctime(time())));
                return 1;
}
