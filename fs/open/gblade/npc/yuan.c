#include <ansi.h>
inherit NPC;
inherit SSERVER;
string ask_gblade();
string help_yuan();
string ask_ba();
string ask_lotch();
string ask_blade();
void do_surrender();

void create()
{
        set_name("陳元貴",({"yuan"}));
        set("long","一個正在打雜的仙劍弟子 , 當你看他的時後 , 你發現他的眼角閃過一絲狡猾的神色 !\n");
        set("gender","男性");
        set("combat_exp",20000);
        set("attitude","peaceful");
        set("age",26);
        set("class","blademan");
        set("str",20);
        set("cor", 30);
        set("per", 25);
        set("int", 30);
        set("cps",20);
        set("con", 30);
        set("spi", 15);
        set("kar", 30);
        set_skill("unarmed",30);
        set_skill("dodge",30);
        set_skill("parry",30);
        set("chat_chance_combat",100);
        set("chat_msg_combat",({
        (: do_surrender :)
        }));
        set("inquiry",([
        "下落"  : "靠 , 幹走我的寶刀還敢來向我問東問西的 \n",
        "寶刀"  :  "哇勒 , 尋我開心啊 ? \n",
        "紫金六陽刀法"  : (: help_yuan :),
        "煉妖壺"   :  (: ask_lotch :),
        "王元霸"  : (: ask_ba :),
        "金刀門"  :  (: ask_gblade :),
        "龍虎刀"  :  (: ask_blade :)
        ]));
        setup();
        add_money("silver",1);
        set("chat_msg",({"chat chat \n"}));
}
void init()
{
        object ob;
        ::init();
        if(interactive(ob=this_player() ) && !is_fighting() )
        {
        remove_call_out("greeting");
        call_out("greeting",2,ob);
        }
        set_heart_beat(1);
}
void greeting(object ob)
{
        if(ob->query_temp("help_yuan") )
        {
        command("say 謝謝你啦 , 我就告訴你煉妖壺的下落吧 !");
        command("say 其實煉妖壺是被魔教所偷走的 !");
        ob->set("lotch",5);
        ob->delete_temp("help_yuan");
        }
}
void do_surrender()
{
        object target, *enemy;
        int i;
        enemy=this_object()->query_enemy();
        i=sizeof(enemy);
        target = offensive_target(this_object());
        if(!target) return ;
        if(target->query_temp("know_blade")&&target->query_temp("know_gblade") )
        {
        if(!target->query("marks/得龍虎刀") && this_object()->query("kee")<60 )
        {
        message_vision("陳元貴說道 : 大俠 , 饒命啊 , 這把龍虎刀給你好了 !\n",target );
        new("/open/gblade/obj/dragon-blade")->move(target);
        target->set("marks/得龍虎刀",1);
        target->delete_temp("know_blade");
        target->delete_temp("know_gblade");
        message_vision("陳元貴拿出了龍虎刀 , 交給了$N\n",target);
        target->remove_enemy(this_object());
        this_object()->remove_enemy(target);
        }
        }
}
string help_yuan()
{
         if(this_player()->query("quests/lotch") || this_player()->query("lotch")>4)
        return "這是一門極強的刀法 !";
        if(this_player()->query("lotch")>3)
        {
        command("say 我還是較喜歡學此刀法 !");
        this_player()->set_temp("can_help_yuan",1);
        return "你能幫我向師父求情 , 重入師門嗎 ?";
        }
        return "嗯 , 好刀法 !";
}
string ask_lotch()
{
        if(this_player()->query("quests/lotch") )
        return "哇 , 你有煉妖壺了 , 可別抓我啊 !\n";
        if(this_player()->query("lotch")<4)
        return "什麼煉妖壺煉魔壺 , 走開 , 別煩我啦 !\n";
        command("say 你以為是我拿的 ? ");
        command("say 我跟你一樣 , 只看到一個空盒子 !");
        return "不過我倒是知到煉妖壺的下落 ! \n";
}
string ask_ba()
{
        if(this_player()->query("quests/lotch") || this_player()->query("lotch")>4)
        return "正是恩師 !\n";
        if(this_player()->query("lotch")<3)
        return "王元霸 , 是誰啊 , 聽這名子倒挺威風的 !\n";
return "哼 , 老賊 , 說什麼我心術不正 , 硬是不傳我紫金六陽刀法 \n";
}
string ask_blade()
{
        if(!present("dragon-tiger blade",this_player()) && this_player()->query("marks/得龍虎刀")&& this_player()->query("marks/還龍虎刀")!=1)
        {
            command("say 弄丟了吧 ？ 還好被我檢了回來 ");
        new("/open/gblade/obj/dragon-blade")->move(this_player());
        message_vision("陳元貴將龍虎刀還給了 $N .\n",this_player());
        return "好好保管好 , 下次可沒這麼幸運了 !\n";
        }
            if(this_player()->query("quests/lotch") || this_player()->query("lotch")>4)
        return "你以經拿去還給恩師啦 !\n";
        if(this_player()->query("lotch")<3)
        return "我不知道你在說什 ?";
        if(this_player()->query("marks/得龍虎刀") )
        return "我不是給你了 !\n";
        if(!this_player()->query_temp("know_gblade") )
        {
        this_player()->set_temp("know_blade",1);
        command("fear");
        return "你還知道些什麼 ?";
        }
        command("say 看來你都知道了 !");
        this_player()->set_temp("know_blade",1);
        this_object()->kill_ob(this_player() );
        return "一不做 , 二不休 , 納命來 !\n";
}
string ask_gblade()
{
        if(this_player()->query("quests/lotch") || this_player()->query("lotch")>4)
        return "就是江湖上最好的門派啊 ! 趕快加入我們吧 !\n";
        if(this_player()->query("lotch")<3)
        return "什麼金刀門啊 , 沒聽過 , 會比我們仙劍強嗎 ?\n";
        if(!this_player()->query_temp("know_blade"))
        {
        this_player()->set_temp("know_gblade",1);
        command("hmm");
        return "你還知道些什麼 ?\n";
        }
        command("say 既然你都知道了 , 我就留不得你 !");
        this_player()->set_temp("know_gblade",1);
        this_object()->kill_ob(this_player());
        return "小子 , 算你命苦 !\n";
}
void heart_beat()
{
        if(this_object()->query("kee") < 60){
        do_surrender();
        if(!this_object()->query_temp("回復")){
        this_object()->add("kee",10);
        this_object()->add("gin",10);
        this_object()->add("sen",10);
        this_object()->set_temp("回復",1);
        }
        }
        ::heart_beat();
}
