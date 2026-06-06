// class_level: 多一些官制(清).... :>      by adam
#include <ansi.h>
#include "/open/open.h"
#define max "max"
#define min "min"
inherit NPC;
inherit F_MASTER;
string do_help();
mapping class_level = ([
        "翰林院編修"      : ([ max : 25 , min : 0 ]),
        "平陽縣師爺"      : ([ max : 50 , min : 25 ]),
        "平陽縣令"        : ([ max : 100 , min : 50 ]),
        "大同縣令"        : ([ max : 150 , min : 100 ]),
        "鳳祥縣令"        : ([ max : 200 , min : 150 ]),
        "晉陽縣令"        : ([ max : 300 , min : 200 ]),
        "桐城縣令"        : ([ max : 400 , min : 300 ]),
        "杭州令"          : ([ max : 500 , min : 400 ]),
        "杭州知府"        : ([ max : 600 , min : 500 ]),
        "開封知府"        : ([ max : 700 , min : 600 ]),
        "廣州知府"        : ([ max : 800 , min : 700 ]),
        "南京知府"        : ([ max : 900 , min : 800 ]),
        "九門提督"        : ([ max : 1000 , min : 900 ]),
        "雲貴總督"        : ([ max : 2000 , min : 1000 ]),
        "兩廣總督"        : ([ max : 3000 , min : 2000 ]),
        "兩江總督"        : ([ max : 4000 , min : 3000 ]),
        "禮部尚書員外郎"  : ([ max : 5000 , min : 4000 ]),
        "禮部尚書"        : ([ max : 6000 , min : 5000 ]),
        "戶部尚書員外郎"  : ([ max : 7000 , min : 6000 ]),
        "戶部尚書"        : ([ max : 8000 , min : 7000 ]),
        "工部尚書員外郎"  : ([ max : 9000 , min : 8000 ]),
        "工部尚書"        : ([ max : 10000 , min : 9000 ]),
        "兵部尚書員外郎"  : ([ max : 11000 , min : 10000 ]),
        "兵部尚書"        : ([ max : 12000 , min : 11000 ]),
        "刑部尚書員外郎"  : ([ max : 13000 , min : 12000 ]),
        "刑部尚書"        : ([ max : 14000 , min : 13000 ]),
        "欽賜龍圖閣大學士": ([ max : 15000 , min : 14000 ]),
        "左丞相"          : ([ max : 25000 , min : 15000 ]),
        "右丞相"          : ([ max : 35000 , min : 25000 ]),
        "欽賜一等千里伯"  : ([ max : 40000 , min : 35000 ]),
        "欽賜二等萬戶侯"  : ([ max : 45000 , min : 40000 ]),
        "欽賜一等定遠侯"  : ([ max : 50000 , min : 45000 ]),
        "欽賜一等定北侯"  : ([ max : 55000 , min : 50000 ]),
        "欽賜二等護國公"  : ([ max : 60000 , min : 55000 ]),
        "欽賜一等鹿鼎公"  : ([ max : 65000 , min : 60000 ]),
        "欽賜一等平南王"  : ([ max : 70000 , min : 65000 ]),
        "欽賜特等平西王"  : ([ max : 80000 , min : 70000 ]),
        ]);
void create()
{
        set_name("陳知衡",({"master chen","chen"}));
        set("long",
        "他是本朝刑部兼吏部高官,主掌大理寺,負責全國司法與官員升等。\n"+
        "有關當官的一些指令以及制度等等的說明請(help officer).\n");
        set("gender","男性");
        set("class","officer");
        set("title","大理寺正卿");
        set("officer_class","大理寺正卿");
        set("officer_power",150);
        set("max_officer_power",150);
        set("office_exp",10000);
        set("nickname",HIY + "執法如山" + NOR);
        set("officer_att","good");
        set("combat_exp",1000000);
        set("attitude","heroism");
        set("age",55);
        set("str", 30);
        set("con", 30);
        set("cps", 30);
        set("max_force",1500);
        set("force",1500);
        set("max_kee",3500);
        set("kee",3500);
        set_temp("apply/armor",150);
        set_skill("literate",80);
        set_skill("force",60);
        set_skill("dodge",40);
        set_skill("parry",60);
        set_skill("unarmed",40);
        set_skill("dagger",60);
        set_skill("be-officer",90);
        set_skill("security",100);
        map_skill("be-officer","security");
        set_skill("dragon-dagger",100);
        map_skill("dagger","dragon-dagger");
        set_skill("chen-steps",60);
        map_skill("dodge","chen-steps");
        map_skill("move","chen-steps");
        set_skill("oneforce",60);
        set_skill("chen-steps",60);
        map_skill("force","oneforce");
        set("force_factor",10);
        set("inquiry", ([
                "幫忙" : (: do_help :),
        ]) );
        setup();
        create_family("陳知衡",1," ");
        carry_object("/open/capital/obj/chen_dagger")->wield();
}

  void attempt_apprentice(object ob)
{
        command("l "+ob->query("id"));
        command("recruit "+ob->query("id"));
        ob->set("officer_class","大理寺郎中");
        ob->set("officer_power",10);
        ob->set("max_officer_power",10);
        ob->set("title","大理寺郎中");
        ob->set("relation/master chen/value",30);
        ob->set("relation/master chen/name","陳知衡");
        command("say 很好 ! 當了官就要知道如何當官﹐你先看看(help officer)吧。");
}
int accept_object(object me,object ob)
{
        string letter_id;
        letter_id=ob->query("id");
        if(letter_id=="chen_letter")
        {
                destruct(ob);
                command("say 咦!我的信，嗯......多謝你啦");
                command("bow"+me->query("id"));
                me->add("taigan_exp",10);
                me->delete_temp("working");
                switch(random(3)){
                        case 1:
                        me->set("taigan_work",5);
                        break;
                        case 2:
                        me->set("taigan_work",6);
                        break;
                        case 3:
                        me->set("taigan_work",7);
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
        if(work!=4 || me->query_temp("working"))
                return "我現在沒什麼事需要你幫忙，去看看別人需不需要吧。\n";
        else
        {
        switch(random(3))
        {
                case 1:
                new("/open/capital/room/sroom/obj/test_letter")->move(me);
                me->set_temp("working",1);
                message_vision("給了$N一封信。\n",me);
                return "你來的正好，我這裡有封信要交給考場的嚴大人，你幫我跑一趟吧。\n";
                break;
                case 2:
                new("/open/capital/room/sroom/obj/soldier_letter")->move(me);
                me->set_temp("working",1);
                message_vision("給了$N一封信。\n",me);
                return "你來的正好，我這裡有封信要交給軍機處的掌兵史，你幫我跑一趟吧。\n";
                break;
                case 3:
                new("/open/capital/room/sroom/obj/lee_letter")->move(me);
                me->set_temp("working",1);
                message_vision("給了$N一封信。\n",me);
                return "你來的正好，我這裡有封信要交給戰情室的李大人，你幫我跑一趟吧。\n";
                break;
        }
        }
}
int check_class_level()
{
        string *class = keys(class_level);
        object me = this_player();
        mapping limit;
        int i;
        for( i = 0 ; i < sizeof(class) ; i ++ )
        {
          limit = class_level[class[i]];
          if( me->query("title") != class[i] && me->query("officer_class") == class[i] )
             me->set("title",class[i]);
          if( me->query("officer_class") == class[i] ) continue;
          if( me->query("max_officer_power") >= limit["min"] && me->query("max_officer_power") < limit["max"] )
          {
             command("say 接聖旨!!!!");
             command("say 皇命召曰:  察 "+me->name(1)+" 任上表現良好,\n"+
                     "            特升任為 "+class[i]+",欽此!!!");
             command("say 恭喜大人!!! 賀喜大人!!!");
             me->set("officer_class",class[i]);
             me->set("title",class[i]);
             return 1;
           }
        }
        // 自己的徒弟不宜稱呼大人
        command("say 嗯 ! 你回來了 ! 很好 !");
        return 1;
}
void init()
{
   add_action("do_return","return");
// if( this_player()->query("family/master_id") == "master chen" )
   if( this_player()->query("class")=="officer" && userp(this_player()) )
     call_out("check_class_level",1);
}
int do_return()
{
        if( this_player()->query("class") != "officer" ) return 0;
//      if( this_player()->query("family/master_id")!="master chen") return 0;
        if( this_player()->query("age") < 21 ) {
                command("say 小伙子 ! 你還年輕﹐這麼就想隱退﹐恐怕聖上會不允准哦 !");
                return 1;
                }
        if( this_player()->query_skill("be-officer") < 50 ) {
                command("say 小伙子 ! 才當個那麼一下官就想走了 ? 分明是沒把老夫放在眼裡 !");
                command("say 不行不行 ! 老夫不准 !");
                return 1;
        }
        if( this_player()->query_temp("return") == 0 )
        {
                command("say 你真的不想當官了嗎 ? ");
                tell_object( this_player() , "請再下一次 (return) 確認。\n");
                this_player()->set_temp("return",1);
                return 1;
        }
        command("say 那麼 .. 再會吧 !");
        this_player()->delete("class");
        tell_object( this_player() , "從今天起﹐你已經變成一個庶民。\n");
        this_player()->delete_skill("be-officer");
        this_player()->delete_skill("security");
        this_player()->delete("max_officer_power");
        this_player()->delete("officer_power");
        this_player()->delete("family");
        this_player()->delete("relation");
        this_player()->delete_skill("chen-steps");
        this_player()->delete_skill("oneforce");
        this_player()->set("title","普通百姓");
        return 1;
}
