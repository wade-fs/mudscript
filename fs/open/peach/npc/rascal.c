// rascal.c

inherit NPC;

void create()
{
        set_name("友人", ({ "rascal" }) );
        set("long",
                "陪同玲玲愛人一起來的友人，然而他聽聞桃花村中的寶物傳說之後起了貪念。
綁走村長企圖想獲取村中的寶物。\n");

        set("race", "人類");
        set("gender", "男性");
        set("age", 26);
        set("class","booker");
        set("nickname","心術不正");
        set("limbs", ({ "頭部", "身體", "左手", "右手", "左腳", "右腳" }) );

        set("str", 15);
        set("cor", 20);
		
		set("attitude","aggressive");

        set_skill("parry", 40);
        set_skill("force", 20);
        set_skill("sunforce",20);
        set_skill("dodge", 30);
        set_skill("linpo-steps",50);
        set_skill("stabber",30);
        set_skill("six-fingers",40);
        map_skill("parry","six-fingers");
        map_skill("force","sunforce");
        map_skill("dodge","linpo-steps");
        map_skill("stabber","six-fingers");

        set("combat_exp", 1200000);

        set("chat_chance", 20);
        set("chat_msg", ({
            (: this_object(), "qeust" :),
            "友人說道: 你這老傢伙還不快把寶物找出來給我！\n",
            "友人說道: 是不是你這老傢伙在說謊！\n",
            "友人說道: 動作快一點，不然先砍下你一隻耳朵！\n",
            "友人說道: 嘿嘿，老傢伙，你是左耳還是右耳不要啦！\n",

        }) );
        setup();
carry_object("/open/ping/obj/fan-2")->wield();

}

void die()
{
 object me;
 if ( !me = query_temp("last_damage_from") )
         me = this_player(1);
 if ( !me ) return;
 me->set_temp("quests/peach/die",1);
 ::die();
}

