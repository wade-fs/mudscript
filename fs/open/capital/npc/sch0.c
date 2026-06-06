#include "/open/open.h"

inherit NPC;
void create()
{
        set_name("李秀才", ({ "scholar lee","lee","scholar" }) );
        set("race", "人類");
        set("class","scholar");
        set("age", 33);
        set("long","他是一位悠游於武林裡的書生, 看他笑容滿面的樣子, "+
        "大概日子還過的不錯吧。\n");

        set("chat_chance",10);
        set("chat_msg", ({
"李秀才吟道:        「楊柳青青江水平，聞郎江上唱歌聲。\n                    東邊日出，西邊雨，道是無晴，還又晴？」\n",
"李秀才吟道:        「萬里清江萬里天，一村桑柘一村煙。\n                    漁翁醉著無人喚，過午醒來雪滿船。」\n",
"李秀才吟道:      「秦樓幾夜愜心期，不料仙郎有別離。\n                    睡覺莫言雲去處，殘燈一盞野娥飛。」\n",
        }));

        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
        "李秀才道﹕出外江湖何必如此動氣呢?!\n",
         }) );

        set_skill("dodge",40);
        set_skill("parry",20);
        set_skill("stabber",40);
        set("combat_exp",4000);
        setup();
        add_money("coin",500);
//        carry_object(CAPITAL_OBJ"fan0")->wield();
        carry_object(CAPITAL_OBJ"head0")->wear();
        carry_object(CAPITAL_OBJ"stabber_book");
}

void defeated_enemy(object ob)
{
        say("李秀才微微揖了一躬道 : 承讓承讓。\n");
        remove_killer(ob);
}
