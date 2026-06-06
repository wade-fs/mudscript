#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("林宏昇",({"pope lin","pope","lin"}));
        set("long",@LONG

        沒有人知道他的來歷，也沒人知道他的武功有多深；是一個神密莫
        測的人物，在三年前因風雲際會，使他創立了〔聖火教〕，也不知
        他是用何方法建立這個龐大的組織，也因為如此, 他被江湖上的人
        稱為〔武林神話〕。

LONG);
        set("gender","男性");
        set("clan_kill",1);
        set("class","prayer");
        set("nickname","武林神話");
        set("title","聖火教皇～～");
        set("combat_exp",7000000);
        set("attitude","heroism");
        set("age",75);
        set("max_kee",15000);
        set("str", 50);
        set("cor", 50);
        set("cps", 45);
        set("per", 30);
        set("int", 42);
        set("marks/tengin",1);
        set("force",50000);
        set("max_force",50000);
        set("force_factor", 40);
        set("max_gin",10000);
        set("max_sen",10000);
        set_skill("cure", 120);
        set_skill("superforce", 150);
        set_skill("dodge", 120);
        set_skill("force",150);
        set_skill("move", 120);
        set_skill("literate",120);
        set_skill("parry", 130);
        set_skill("array",130);
        set_skill("fire-array",130);
        set_skill("unarmed",130);
        set_skill("canon",150);
        set_skill("literate",120);
        set_skill("shift-steps",150);
        set_skill("universe",140);
        map_skill("force","superforce");
        map_skill("dodge","shift-steps");
        map_skill("move","shift-steps");
        map_skill("parry","universe");
        map_skill("array","fire-array");
        map_skill("unarmed","universe");
        set("functions/blood/level",60);
        set("functions/tengin/level",120);
        set("chat_chance", 1);                                                  
        set("chat_msg", ({                                                      
                CYN + "教皇吟道﹕「慾海浮沈名利爭，電光火石此步生；\n
                        紅塵世事揮不盡，渡世不笑是痴人。」\n" + NOR,                                                          
                CYN + "教皇笑道﹕「孤卒浴血鬥志高，賢仕善謀腦中計，\n
                        一炮轟開險關道，單車護帥越天河。」\n" + NOR,                                                          
                CYN + "教皇嘆道﹕「萬里雄兵氣如虹，千秋定論難爭峰；\n
                        昊日顯照星光掩，百川匯宗誰與共。」\n" + NOR,                                                          
                CYN + "教皇樂道﹕「百年世事空華裡，一片身心水月間；\n
                        獨許\萬山深密處，晝長趺坐掩松關。」\n" + NOR,                                                          
                CYN + "教皇悲道﹕「命裏有時終須有，凡事不可強求；\n
                        時至運就到，蒼天不會辜負苦心人啊。」\n" + NOR,                                                          
                CYN + "教皇念道﹕「夜涼撫琴千山月，路遙迷人千種花；\n
                        棋罷不知人換世，酒欄無奈客恩家。」\n" + NOR,                                                          
                CYN + "教皇沈吟道﹕「隱居幽靈古洞天，苦學秘笈無限年；\n
                        誰若超越一線界，休怪氣功穿腦田。」\n" + NOR,                                                          
                CYN + "教皇說道﹕「靜月禁地是仙境，休望侵犯取月靈；\n
                        若要逞強不聽勸，閃電霹靂奪性命。」\n" + NOR,                                                          
        }) );                                                                   
        set("chat_chance_combat",40);
                set("chat_msg_combat", ({
                (: perform_action, "universe.tengin" :),
//              (: exert_function, "blood" :),
//              (: perform_action, "force.blood1" :),
//              (: perform_action, "force.blood2" :),
                (: perform_action, "force.blood3" :),
        }));
        setup();

        add_money("thousand-cash",20);
        carry_object("/open/prayer/obj/boris-boots")->wear();
        carry_object("/open/prayer/obj/boris-cloth")->wear();
        carry_object("/open/prayer/obj/boris-hat")->wear();
        carry_object("/open/prayer/obj/boris-hands")->wear();
        carry_object("/open/prayer/obj/kylin-belt")->wear();
        carry_object("/open/prayer/obj/dragon-icer")->wield();
        create_family("聖火教",1,"教皇");
        carry_object("open/prayer/obj/lin-head");

}

void init()
{
        add_action("do_join","join");
        add_action("do_select","select");
        add_action("do_verify","verify");
}

int accept_fight(object who)
{
return notify_fail("教皇冷冷的道 : 去.去..去...少來煩我。\n");
}

int do_verify(string arg)
{
object me,ob,ob1;
me=this_player();
ob=new("open/prayer/obj/woodboard");
ob1=new("open/prayer/obj/ironboard");
if( arg!="board")
  {
    write("你要申請什麼\n");
    return 1;
   }
if(me->query("family/family_name")!="聖火教")
  {
    write("只有聖火教徒才會有信物\n");
    return 1;
  }

 if( present("wood board",me) || present("iron board",me) )
  {
    write("你已經申請過了\n");
    return 1;
  }
  
 if ( me->query("marks/文武星君") )
    {
    write("這是聖火教幹部的專用鐵牌!!可不要掉了!!\n");
    ob1->move(me);
      return 1;
    }
    else
    {
    write("這是聖火教的信物 ,望你好好保存 ,切勿遺失了\n");
    ob->move(me);
  return 1;
  }
}

  void attempt_apprentice(object ob)
{
        if(ob->query("marks/聖火八天門")==1)
        {
        if((int)this_player()->query("combat_exp")<=200000)
        {
        command("? " +ob ->query("id"));
        command("say 你不是拜過八天門的門主了嗎?");
        command("say 以你的程度還不夠資格跟我學習武學與教務的處理吧!");
        command("say 好好跟著你自己的師父多學幾年吧!");
        return 0;
        }
        command("look "+ob->query("id"));
        command("pat");
        command("say 好,你果然是可造之才,你可以去找三位長老作為你武學的指導!");
        ob->delete("family");
        command("say 你想選擇(select)哪一位長老呢?");
        command("say 傳功長老(gonfu_elder)，執法長老(lawyer_elder)還是戒律長老(behavior_elder)？");
        ob->set_temp("allow_select",1);
        }
        if(ob->query("marks/聖火三長老")==1)
        {
        if((int)this_player()->query("combat_exp")<=900000)
        {
        command("? " +ob ->query("id"));
        command("say 你不是已經拜過三位長老作為老師了嗎?");
        command("say 以你的程度來看，目前還不夠資格跟我學習武學與教務的處理吧!");
        command("say 好好跟著長老們再多學幾年吧!");
        return 0;
        }
        command("look "+ob->query("id"));
        command("pat");
        command("say 好,你果然不是泛泛之輩,你可以去找教內的文武星君作為你武學的指導!");
        ob->delete("family");
        command("say 你可以選擇武星君(warrior)或是文星君(literate)");
        ob->set_temp("allow_select",1);
        }
        if(ob->query("marks/文武星君")==1)
        {
        if((int)this_player()->query("combat_exp")<=2500000)
        {
        command("? " +ob ->query("id"));
        command("say 你不是已經是文武星君的入室弟子了嗎?");
        command("say 以你的程度還不夠資格跟我學習武學與教務的處理吧!");
        command("say 好好跟著文武星君多磨練磨練吧!");
        return 0;
        }
        command("look "+ob->query("id"));
        command("pat");
        command("say 好,你果然是可造之才,從今後就由本教主親自教導!");
        ob->delete("family");
        command("recruit "+this_player()->query("id"));
        this_player()->set("title","聖火教嫡傳弟子");
        message("mud","聖火教皇～～林宏昇放聲大笑: \n
        哈哈哈哈....本教主實在太高興啦！！\n
        "+this_player()->name()+"今後聖火教的重擔就落在你的肩上了，\n
                        好好幹吧!!老夫不會虧侍你的!!\n",users());
        return ;
        }
            command("hmm");
        command("say 我教務繁忙 ,你去找聖火八天門的門主吧 !");
        command("say 你想進入(select)哪一門呢?");
        command("say 你可以選擇天機門(tangi)，天樞門(tanshu)，天權門(tanchun)");
        command("say 你可以選擇天璇門(tanshun)，玉衡門(uhen)，開陽門(kiyan)");
        command("say 你可以選擇瑤光門(youkoun)，陣勢門(zhenche)");
        ob->set_temp("allow_select",1);
            }

int do_join()
        {
        if(this_player()->query("class"))
                return notify_fail("你已經加入其他工會了。\n");
        if(this_player()->query("officer_class"))
                return notify_fail("教皇冷冷的說道：你在中原己當過官了，我聖火教不歡迎你!!\n");
        this_player()->set("class","prayer");
        message("mud","\n聖火教皇～～林宏昇 : 哈.哈..哈...\n
各位聖火教的弟子們，\n
讓我們歡迎" +this_player()->name()+"加入我聖火教!!\n\n",users());
        return 1;
}
        int do_select(string str)
        {
        object who;
        who=this_player();
        if(!who->query_temp("allow_select"))
        {
        command("say 我又沒答應讓你挑? ");
        return 1;
        }
        if(who->query_temp("have_say")==1)
        {
        message_vision(sprintf(HIC + "$N說道﹕"+str+"\n" + NOR),who);
        command("say 你不是挑過了?");
        return 1;
        }
        if(str=="天機門" ||  str == "tangi")
        {
         message_vision(HIC + "$N說道﹕天機門\n" + NOR,who);
        this_player()->set_temp("allow_1",1);
        command("smile");
        command("say 嗯 ,你就去加入天機門吧!");
        this_player()->set_temp("have_say",1);
        return 1;
        }
        if(str == "天樞門" || str == "tanshu")
        {
        message_vision(HIC + "$N說道﹕天樞門\n" + NOR,who);
        this_player()->set_temp("allow_2",1);
        command("smile");
        command("say 嗯 ,你就加入天樞門吧!");
        this_player()->set_temp("have_say",1);
        return 1;
        }
        if(str == "天權門" || str == "tanchun")
        {
        message_vision(HIC + "$N說道﹕天權門\n" + NOR,who);
        this_player()->set_temp("allow_3",1);
        command("smile");
        command("say 嗯 ,你就進去天權門修練吧!");
        this_player()->set_temp("have_say",1);
        return 1;
        }
        if(str == "天璇門" || str == "tanshun")
        {
        message_vision(HIC + "$N說道﹕天璇門\n" + NOR,who);
        this_player()->set_temp("allow_4",1);
        command("smile");
        command("say 嗯 ,你就到天璇門好好磨練吧!");
        this_player()->set_temp("have_say",1);
        return 1;
        }
        if(str == "玉衡門" || str == "uhen")
        {
        message_vision(HIC + "$N說道﹕玉衡門\n" + NOR,who);
        this_player()->set_temp("allow_5",1);
        command("smile");
        command("say 嗯 ,你就加入玉衡門吧!");
        this_player()->set_temp("have_say",1);
        return 1;
        }
        if(str == "開陽門" || str == "kiyan")
        {
        message_vision(HIC + "$N說道﹕開陽門\n",who);
        this_player()->set_temp("allow_6",1);
        command("smile");
        command("say 嗯 ,你就前往開陽門學習吧!");
        this_player()->set_temp("have_say",1);
        return 1;
        }
        if(str == "瑤光門" || str == "youkoun")
        {
        message_vision(HIC + "$N說道﹕瑤光門\n" + NOR,who);
        if(this_player()->query("gender") != "女性")
        command("say 你不是女性, 瑤光門恐怕不會收你的! 另選一個吧!");
        else
        {
        this_player()->set_temp("allow_7",1);
        command("smile");
        command("say 嗯 ,你就前去瑤光門拜師學藝吧!");
        this_player()->set_temp("have_say",1);
        }
        return 1;
        }
        if(str == "陣勢門" || str == "zhenche")
        {
        message_vision(HIC + "$N說道﹕陣勢門\n" + NOR,who);
        this_player()->set_temp("allow_8",1);
        command("smile");
        command("say 嗯 ,你就前去陣勢門拜師學藝吧!");
        this_player()->set_temp("have_say",1);
        return 1;
        }
        if(str == "傳功長老" || str == "gonfu" || str == "gonfu_elder")
        {
        message_vision(HIC + "$N說道﹕傳功長老\n" + NOR,who);
        this_player()->set_temp("allow_9",1);
        command("smile");
        command("say 嗯 ,你就去傳功長老那兒學藝吧!");
        this_player()->set_temp("have_say",1);
        return 1;
        }
        if(str == "執法長老" || str == "lawyer" || str == "lawyer_elder")
        {
        message_vision(HIC + "$N說道﹕執法長老\n" + NOR,who);
        this_player()->set_temp("allow_10",1);
        command("smile");
        command("say 嗯 ,你就去執法長老那兒學藝吧!");
        this_player()->set_temp("have_say",1);
        return 1;
        }
        if(str == "戒律長老" || str == "behavior" || str == "behavior_elder")
        {
        message_vision(HIC + "$N說道﹕戒律長老\n" + NOR,who);
        this_player()->set_temp("allow_11",1);
        command("smile");
        command("say 嗯 ,你就去戒律長老那兒學藝吧!");
        this_player()->set_temp("have_say",1);
        return 1;
        }
        if(str == "武星君" || str == "warrior")
        {
        message_vision(HIC + "$N說道﹕武星君\n" + NOR,who);
        this_player()->set_temp("allow_12",1);
        command("smile");
        command("say 嗯 ,你就去武星君那兒學藝吧!");
        this_player()->set_temp("have_say",1);
        return 1;
        }
        if(str == "文星君" || str == "literate")
        {
        message_vision(HIC + "$N說道﹕文星君\n" + NOR,who);
        this_player()->set_temp("allow_13",1);
        command("smile");
        command("say 嗯 ,你就去文星君那兒學藝吧!");
        this_player()->set_temp("have_say",1);
        return 1;
        }
        command("say 沒這人!");
        return 1;
        }
int accept_kill(object ob)
{
        int i;
        object ob1, hu_fa;
        ob1 = this_object();
        command("exert blood");
        if( !present("hu-fa", environment(ob)) ) {
        tell_room(environment(ob),HIW + "\n突然！衝出兩位護法!!\n\n" + NOR);
        for(i=0;i<3;i++)
        {
        hu_fa = new("/open/prayer/npc/hu_fa");
        hu_fa->move(environment(ob));
        hu_fa->command("guard pope");
        hu_fa->command("follow "+ob->query("id"));
        hu_fa->kill_ob(ob);
        }}
        write("護法縱身飛撲過來叫道：誓死保護教主！！\n");
        write("林宏昇滿臉殺氣的說道：「無知小輩!!受死吧!!!」\n");
        kill_ob(ob);
        command("perform universe.tengin");
        return 1;
}
void greeting(object ob)
{
        if (ob->query_skill("coldpoison", 1))
//      if ((present("five poison", ob)) || (present("dark poison", ob)) || (present("faint poison", ob)) || (present("rose poison", ob)) )
        {
        command("say 本教主一生光明磊落！！最痛恨學有毒術之人！！");
        kill_ob(ob);
        }
        if( ob->query("class")=="dancer")
        {
        command("say 本教主最恨那些利用美色之人！！");
        kill_ob(ob);
        }
    return;
}
void die()
{

   object winner = query_temp("last_damage_from");
   string name = winner->query("name");
   tell_object(users(),HIR + "
       遠從西域傳來一聲怒吼!!『聖火教主』林宏昇不顧傷勢!!強運身上內力,使出了
      "+HIW+"先天乾坤功第七絕
                          『"+HIC+"天"+HIG+"驚"+YEL+"地"+BLU+"動"+HIW+"』" + HIR + "
       一時之間，天地變色!!狂風怒嘯!!九天真氣、九地真氣，齊湧至林宏昇之体內!!!
       忽然間!!轟~~一聲巨響!!!林宏昇無法駕駛身上的九天真氣!!真氣爆体而出!!血肉模糊!!

     "+HIC+"大俠"+HIY+name+HIC+"在旁笑道：聖火教氣數以盡!!今後是我稱霸的時代了!!哈哈!!" + NOR);
  :: die();
}


void heart_beat()
{
 object me=this_object();
 if(random(100) < 20 && is_fighting()) {
   command("perform universe.tengin");
   me->delete_busy();
   me->clear_condition();
 }
 if( random(100) < 10)
 {
  if( is_fighting() )
  {
   if( query("kee") < query("max_kee") )
    message_vision(HIR + "\n林宏昇出渾天心法之冰心訣，身上的傷口奇蹟式癒合了\n" + NOR,me);
    me->receive_heal("kee",1000);
    me->receive_heal("gin",200);
    me->receive_heal("sen",200);
    me->delete_busy();
    me->clear_condition();
  }
 }
::heart_beat();
}
