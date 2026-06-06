inherit NPC;
#include <combat.h>
#include "/open/open.h"
string do_thief();
string do_help();
void create()
{
        set_name("紀無塵", ({ "chi wu-cheng","chi", "cheng" }) );
        set("title", "總理執事");
        set("nickname", "京城之光");
        set("class","officer");
        set("gender", "男性" );
        set_max_encumbrance(1000000);
        set("age", 46);
        set("str", 20);
        set("cor", 20);
        set("cps", 20);
        set("int", 30);
        set("spi", 20);
        set("kar", 26);
        set("per", 20);
        set("con", 30);

        set("max_force", 2000);
        set("force", 2000);
        set("force_factor", 5);

        set("long", @LONG
    人稱『京城之光』，人說其斷案如神，決不徇私茍且。所以這裡的
百姓都很敬愛他。也因為他的功績輝煌，先皇特賜其一柄尚方寶劍，准
其將惡慣滿盈之人，先斬後奏!!
LONG);

        set("combat_exp",500000);
        set("score", 30000);

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
        "無塵大人喝道：大膽狂徒!!  拿下!!\n",
        "無塵大人喝道：公堂之上竟敢撒野!!  給我嚴懲!!\n"
        }) );

        set_skill("unarmed", 30);
        set_skill("force",  20);
        set_skill("parry",  20);
        set_skill("dodge",  20);
        set_skill("sword",  20);
        set_skill("literate", 90);

        set("inquiry", ([
          "機器人" : "哼!! 誰被我抓到是機器人的話，斬立決!!",
          "accuse" : "想緝捕機器人的話，請先到門口擊鼓申冤(accuse)。",
          "thief"  : (: do_thief :),
          "測試"   : "想抓賊(thief)就得先經過我測試, 若能連接我五招便算過關了。",
          "test"   : "想抓賊(thief)就得先經過我測試, 若能連接我五招便算過關了。",
          "accept" : "要接受測試嗎? 那就打(accept test)。",
          "幫忙"   : (: do_help :),
        ]) );

        setup();
        carry_object(HALL_NPC"obj/god_sword")->wield();
        carry_object(HALL_NPC"obj/o_cloth")->wear();
}

int accept_object(object me,object ob)
{
        string letter_id;
        letter_id=ob->query("id");
        if(letter_id=="chi_letter")
        {
                destruct(ob);
                command("say 咦!我的信，嗯......多謝你啦");
                command("bow"+me->query("id"));
                me->add("taigan_exp",10);
                me->delete_temp("working");
                switch(random(3)){
                        case 1:
                        me->set("taigan_work",1);
                        break;
                        case 2:
                        me->set("taigan_work",2);
                        break;
                        case 3:
                        me->set("taigan_work",3);
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
        if(work!=1 || me->query_temp("working") ||me->query("class")!="taigan")
                return "我現在沒什麼事需要你幫忙，去看看別人需不需要吧。\n";
        else
        {
        switch(random(3))
        {
                case 1:
                new("/open/capital/room/sroom/obj/yen_letter")->move(me);
                me->set_temp("working",1);
                message_vision("給了$N一封信。\n",me);
                return "你來的正好，我這裡有封信要交給內務監的嚴公公，你幫我跑一趟吧。\n";
                break;
                case 2:
                new("/open/capital/room/sroom/obj/chang_letter")->move(me);
                me->set_temp("working",1);
                message_vision("給了$N一封信。\n",me);
                return "你來的正好，我這裡有封信要交給膳食監的張公公，你幫我跑一趟吧。\n";
                break;
                case 3:
                new("/open/capital/room/sroom/obj/chan_letter")->move(me);
                me->set_temp("working",1);
                message_vision("給了$N一封信。\n",me);
                return "你來的正好，我這裡有封信要交給管事監的陳公公，你幫我跑一趟吧。\n";
                break;
        }
        }
}
string do_thief()
{
        object me=this_player();
        if( me->query("quests/catch_thief") == 0 )
        {
          if( me->query_temp("thief") == 0 )
            me->set_temp("thief",1);
          return (RANK_D->query_respect(me)+"是有意幫忙抓京城大盜的嗎? "+
                "只是最近有\許\多\沒本事的人前來應徵\n, "+RANK_D->query_respect(me)+
                "若有本事的話請先接受測試吧(accept test)。");
        }
        else
        {
          command("smile");
          command("pat "+me->query("id"));
          return ("這件事真是多虧了你, 如今京城又恢復平靜了。");
        }
}
void init()
{
        add_action("do_accept","accept");
}
int do_accept(string str)
{
        int i;
        object ob=this_object();
        object me=this_player();
        object mark=new(CAPITAL_OBJ"mark");
        if( me->query_temp("thief") == 0)
          command("say 先問問為何要測試吧。");
        if( me->query_temp("thief") > 1)
          command("say 不是測試過了嗎?");
        if( me->query_temp("thief") == 1)
        {
        if( str=="test")
        {
          command("say 好! 待老夫來試試你! 小心了");
          for(i=0;i<5;i++)
            COMBAT_D->do_attack(ob, me, ob->query_temp("weapon"), TYPE_QUICK);
          if( me->query("kee") > 1 )
          {
            command("say 果然不\愧\為\真英雄, 那我就將這件事原原本本的說與你聽了");
            command("thank "+me->query("id"));
            command("say 這京城大盜目前為止已得手不下數次, 連京城首富乾通天的宅第也\n"+
            "            遭殃了, 因此這才驚動皇上下令一個月之內必須破案, 既然"+RANK_D->query_respect(me)+
            "\n            自告奮勇, 那這件事就拜託你了。將此名大盜逮捕歸案, 則必定重重有賞。");
            message_vision("$N交給$n一面「衙門令牌」。\n",ob,me);
            mark->move(me);
            command("say 希望這面令牌對你辦案能有所助益。");
            me->set_temp("thief",2);
          }
          else
          {
            command("say 罷了罷了, 我還是繼續等真英雄來吧");
            command("sigh");
          }
        }
        else
          write("接受什麼?!\n");
        }
        return 1;
}

int accept_object(object me, object man)
{
        string target = "趙琴風";
        object ob=this_object();
        object reward;
        if( me->query_temp("thief") < 2 )
          return notify_fail(ob->query("name")+"說道﹕疑..我好像沒有託你辦這件事嘛。既然你這麼熱心, 那就謝囉。\n");
        if( man->query("victim_name") == target || man->query("name") == target )
        {
          command("say 真是太好了, 我託付你的事終於順利的達成了。");
          if( man->query("name") == target )
          {
            command("say 按照約定, 這就是你應得的賞金。\n");
            reward = new("/obj/money/gold");
            reward->set_amount(5);
            reward->move(me);
            message_vision("$N賜給$n五兩黃金。\n",ob,me);
          }
          else
          {
            command("say 可惜這京城大盜已死, 因此賞金只有一半了。");
            reward = new("/obj/money/gold");
            reward->set_amount(2);
            reward->move(me);
            message_vision("$N賜給$n二兩黃金。\n",ob,me);
          }
          if( !me->query("quests/catch_thief") )
          {
            write("\n\n**完成京城大盜之謎***\n你得到實戰經驗 200。\n");
            me->add("combat_exp",200);
            if( me->query("class") == "officer" )
            {
              write("你得到政治權力 20。\n");
              me->add("max_officer_power",20);
            }
            me->set("quests/catch_thief",1);
            me->delete_temp("thief");
          }
          destruct(man);
        }
        return 1;
}


