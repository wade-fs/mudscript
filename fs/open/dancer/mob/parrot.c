inherit NPC;

void create()
{
        set_name("彩紋九官鳥", ({ "parrot", "bird" }) );
        set("race", "野獸");
        set("age", 1);
        set("long", "你尋著問候聲望來, 看見一隻羽尾著七彩花紋的九官鳥.\n");
        set("str", 20);
        set("cor", 15);
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("chat_chance", 8);
        set("chat_msg", ({
                "九官鳥 飛到你的肩膀親切的對你說『歡迎光臨』。\n",
                "九官鳥 紅著臉對你說『小姐都叫我 小虹』。\n",
                "九官鳥 突然張開翅膀飛了出去, 宛如一條長虹越過窗前。\n",
                "九官鳥 興奮的對你說『看看窗外, 外面好美喔』。\n" }) );

        set_temp("apply/attack", 1000);
        set_skill("dodge",100);
        set_skill("unarmed",70);
        set("combat_exp",10000);
        set_temp("apply/armor", 3000);
        setup();
}
