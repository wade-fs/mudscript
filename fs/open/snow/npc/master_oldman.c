#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("神秘老人",({"oldman"}));
set("long", "一個看起來全身髒盻盻的老人，腳上還有一個腳銬，看起來像是被關在這裡的。\n");
        set("gender", "男性" );
        create_family("魔刀莫測",1," ");
        set("title","");
        set("age",70);
        set("str",44);
        set("class","blademan");
        set("guild_class","blademan");
        set("cor", 30);
        set("cps", 27);
        set("int", 24);
        set("max_force",3000);
        set("force",3000);
        set("force_factor",15);
        set("kee",5000);
        set("max_kee",5000);
        set("bellicosity", 1500);
        set_skill("force", 100);
        set_skill("blade", 100);
        set_skill("dodge", 70);
        set_skill("move", 70);
        set_skill("powerforce", 100);
        set_skill("dragon-blade", 120);
        set_skill("parry", 95);
        map_skill("parry","dragon-blade");
        map_skill("blade","dragon-blade");
        map_skill("force","powerforce");
        set("combat_exp", 1500000);
        set("chat_chance_combat",80);
        set_temp("apply/armor",90);
        set_temp("apply/damage",90);
        set("chat_msg_combat",({
        (: perform_action, "blade.power-dest" :),
      }));

        set("inquiry", ([
"腳銬":
 "這個腳銬是用千年寒鐵石打造的，一般兵器是砍不斷的。\n",
           "千年寒鐵石":
"這是經過千年孕育而成的堅硬石塊，除非有神兵利器，不然無
法砍斷。\n",
           "神兵利器":
"聽說人間至寶「金鱗蟒邪」配上「天邪石」可以毀滅千年寒鐵石。\n",
           "金鱗蟒邪":  "聽說金鱗蟒邪好像落在茅山派手上。\n",
           "天邪石":   "天邪石在獨孤愁傳人的手裡。\n",
        ]) );

        add_temp("apply/attack",30);
        add_temp("apply/dodge",30);
        setup();
        carry_object("/daemon/class/blademan/obj/iceblade")->wield();
}
void attempt_apprentice(object ob)
{
        if(this_player()->query_skill("dragon-blade",1)<105)
        {
        command("say 滾！你給我滾開！\n");
        return ;
        }
        command("smile");
        command("say 嗯，果然青出於藍，從今後老夫親自傳授於你。");
        command("say 但是魔刀武學不能外傳，切記，切記。");
        ob->delete("family");
        command("recruit "+this_player()->query("id"));
        this_player()->set("title","魔刀絕世傳人");
        this_player()->set("no_recruit", 1);
        this_player()->delete("can_apprentice");
        message("system",HIB"魔刀莫測縱聲狂笑:
哈哈哈哈～～魔刀一出～～血流成河～～無所匹敵。\n"NOR,users());
        return ;
        }
int accept_object(object who,object ob)
{
    string ob_id;
    ob_id=ob->query("id");
    if(who->query("quests/blade_out")==0)
    {
    if(ob_id=="stone")
    {
    destruct(ob);
    command("say 我沒看錯吧，你竟然能將天邪石拿到手！");
    this_player()->set("give_1",1);
    }
    if(ob_id=="snake sword")
    {
    destruct(ob);
    command("say 太好了，這正是我需要的東西！");
    this_player()->set("give_2",1);
    }
    }
if(who->query("give_1")==1 && who->query("give_2")==1)
{
    command("say 太好了！");
    message_vision(
             HIY
"$n將天邪石的神力注入金鱗蟒邪之中，然後運勁一砍，將腳銬砍斷。\n" NOR,this_player(),this_object());
    CHANNEL_D->do_channel(this_object(),"mud",HIR
"遠處傳來魔刀莫測的大喝:\n我自由了！哈哈哈哈！\n獨孤愁！你這個老賊等著吧！我要一雪這十幾年禁錮之恨！\n"NOR);
           command("say 感謝你釋放了我，我這就去宰了獨孤老賊。");
           command("say 不過看在你曾幫我，好吧，我將部分內力傳給你。");
           this_player()->add("max_force",100);
           this_player()->add("force",100);
           who->set("quests/blade_out",1);
           who->delete("give_1");
           who->delete("give_2");
   }
      else
{
             if(ob_id!="snake sword" && ob_id!="stone" ) 
             return 1;
}
}
