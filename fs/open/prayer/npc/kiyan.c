#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;
object ob1=this_object();
int have_say;
string ask_reason()
{
    object ob2=this_player();
    if( ob2->query("family/master_name") =="秦憶詩" )
    {
    ob2->set_temp("can_ask",1);
    return("這是我玉女派的劍法!!我乃是玉女派的掌門人......\n
    可是自從我的師姐陸綺芙陰謀奪取劍譜之後.....\n");
    }
    else
    {
    return("這位俠士看來並非本門的弟子, 請回吧!!");
    }
}

string ask_lu()
{
    object ob2=this_player();
    if( (ob2->query("family/master_name") =="秦憶詩") && ob2->query_temp("can_ask",1) )
    {
    ob2->delete_temp("can_ask");
    ob2->set_temp("can_kill",1);
    return("師姐陸綺芙她設計陷害我, 使得我被門人[誤會].....\n
    不得已只好帶著另一位小師妹遠走西域.....\n");
    }
    else
    {
    return("這位俠士看來並非本門的弟子, 請回吧!!");
    }
}

string ask_misunder()
{
    object ob2=this_player();
    if( (ob2->query("family/master_name") =="秦憶詩") && ob2->query_temp("can_kill") )
    {
    return("現在多說也沒人會相信了, 不過如果能殺了師姐陸綺芙, 就可消我心頭之怨了.\n
    去找我的另一個[小師妹], 她會告訴你師姐的藏身處的!!\n");
    ob2->delete_temp("can_kill");
    ob2->set_temp("go_kill",1);
    }
}

string ask_book()
{
    object ob2=this_player();
    object ob3=new("/open/prayer/obj/girlbook");
    if( ob2->query("quests/girlsword",1) && !present("girlbook",ob2) )
    {
    ob3->move(this_player());
    return "你務必要好好的學習玉女派的劍法!!\n";
    }
    else
    {
    return "劍譜我藏起來了!!不過掌門佩劍[紅炘劍]我放在開陽門的某一個地方!!\n";
    }


}   

void create()
{
        set_name("秦憶詩", ({"chi i-zhi","chi","i-zhi"}));
        set("long",@LONG

        開陽門的門主！原本是中原武林的一位小師太，貴為該派的
        掌門人, 可是不知為何跑到西域來加入聖火教, 一手天女散
        花劍法出神入化, 而聖火教的三大絕學中, 她也是屬於一等
        一的好手!!

LONG);
        set("gender","女性");
        set("class","prayer");
        set("family/master_name","林宏昇");
        set("combat_exp",1000000);
        set("attitude","heroism");
        set("age",28);
        set("title","開陽門主");
        set("kee",5000);
        set("max_kee",5000);
        set("force",9000);
        set("max_force",9000);
        set("max_gin",4000);
        set("max_sen",4000);
        set("force_factor",5);
        set_skill("holy-force", 50);
        set_skill("superforce", 80);
        set_skill("cure", 40);
        set_skill("dodge",60);
        set_skill("force",50);
        set_skill("canon",80);
        set_skill("move", 40);
        set_skill("parry", 80);
        set_skill("unarmed",80);
        set_skill("literate",40);
        set_skill("shift-steps",60);
        set_skill("universe",80);
        map_skill("force","superforce");
        map_skill("dodge","shift-steps");
        map_skill("move","shift-steps");
        map_skill("parry","universe");
        map_skill("unarmed","universe");
        set("functions/bluesea/level",40);
        set("inquiry",([
        "天女散花劍法":"當初是因為某種原因, 所以不得已才淪落到西域的!!\n",
        "原因":(: ask_reason :),
        "陸綺芙":(: ask_lu :),
        "玉女派":"玉女派是中原的一個小門派, 可是劍法乃是高人所創, 因為師父傳位於我, 所以劍譜也傳給了我!!\n",
        "劍譜":(: ask_book :),
        "紅炘劍":"是掌門人專用的寶劍, 與劍法配合互使的話, 殺傷力倍增!!\n",
        "誤會":(: ask_misunder :),
        ]));
        set("chat_chance",5);
        set("chat_msg", ({
        HIC+"秦憶詩輕吟:人善養心～而心如皓月清風～!!\n\n"+NOR
        HIC+"事善修身～而身似行雲流水～!!\n\n"+NOR,
        HIC+"武林萬物～皆為生而輪迴～!!\n\n"+NOR
        HIC+"百家兵器～獨本劍得精髓～!!\n\n"+NOR,
        }) );
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
        (: perform_action("force.bluesea1") :),
        (: perform_action("force.bluesea2") :),
        (: exert_function("bluesea") :),
        }));
        setup();
    add_money("gold",5);
    carry_object("/open/prayer/obj/emery-robe")->wear();
    carry_object("/open/prayer/obj/hat")->wear();
    carry_object("/open/prayer/obj/emery-belt")->wear();
    carry_object("/open/prayer/obj/emery-firer")->wield();
    carry_object("/open/prayer/obj/emery-armband")->wear();
    create_family("開陽門",5,"門主");
}

void attempt_apprentice(object ob)
{
        if(!ob->query_temp("allow_6"))
        {
        command("say 沒有教主的同意,我不敢擅自做主讓你進門!");
        return 0;
        }
        command("smile");
        command("say 既然是教主的意思,那你就進入我開陽門吧!");
        command("say 聖火教的絕學博大精深,可不是那麼好學的!");
        command("say 想學得蓋\世武學就得好好修習內功\的基礎!");
        command("recruit "+ob->query("id"));
        ob->set("marks/聖火八天門",1);
        this_player()->set("title","聖火教開陽門俗家弟子");
        }

void greeting(object ob)
{
        if (ob->query_skill("coldpoison", 1))
//      if ((present("five poison", ob)) || (present("dark poison", ob)) || (present("faint poison", ob)) || (present("rose poison", ob)) )
      {
       command("say 教主有令！！凡是學有毒術之人，殺無敕！！");
        kill_ob(ob);
     }
       if( ob->query("class")=="dancer")
        {
        command("say 教主有令，見到舞者-----格殺勿論！！");
        kill_ob(ob);
     }
    return;
}

int accept_object(object ob2, object obj, object ob3)
{
        if( obj->query("name") == "玉鐕" )
        {
          command("pat "+getuid(ob2));
          command("say 太好了, 你真的將我師姐殺死了!!謝了。");
          if( ob2->query("family/master_name") == "秦憶詩" && !ob2->query("marks/girlsword") && ob2->query_temp("will_kill") )
          {
          command("say 既然你幫我清除門內叛逆, 我便將此劍譜傳授與你吧。");
          write(this_object()->query("name")+"看著秘笈隨手演練了一遍給你看。\n\n"+
          "你覺得此一劍法似乎異常地適合你, 你的武學修養又可以更進一層了。\n\n"+
          "你學會了玉女派的「天女散花劍法」。\n\n");
              ob2->set_skill("girlsword",10);
              ob2->set("quests/girlsword",1);
              ob3=new("/open/prayer/obj/girlbook");
              ob3->move(this_player());
          }
          destruct(obj);
        }
        else
        command("? "+getuid(ob2));
        return 1;
}
