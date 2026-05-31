//陰陽步法 by bss
#include <ansi.h>
#include <combat.h>
inherit SKILL;

string *dodge_msg = ({

        "\n"HIC"$n腳踩奇步，忽左忽右，有如游魚般繞到了$N的身後，使$N的攻勢落空。"NOR"\n",

        "\n"HIC"$n的腳下忽然加快，忽地一閃，竟然從$N的眼前消失，讓$N不知所措。"NOR"\n",

        "\n"HIC"$n的身體伏低，雙腳離地，身形急轉，如一道旋風般從$N身旁竄過，躲過了\n$N的必殺招式。"NOR"\n",

        "\n"HIC"$n單腳站立，身體隨風前後左右擺\動，恰好的躲過了$N的招式。"NOR"\n",

        "\n"HIC"$n的身體不斷的轉圈，在狹小的空間中快速的移動，使$N找不到$n的確實位\n置，招式落空。"NOR"\n",

});



int valid_enable(string usage) {
        return (usage=="dodge")||(usage=="move");

}

int valid_learn(object me)
{
        int level,skill;
        level=me->query("taigan_level",1);
        skill=me->query_skill("taigan-steps",1);
        if(me->query("class")!="taigan"){
                return notify_fail("只有太監能學陰陽步法");
                return 0;
                }
        switch(level){
                case 5:
                        return 1;
                        break;
                case 6:
                        if(skill>80){
                                return notify_fail("你的官品不夠，無法學習更高深的武技。\n");
                                return 0;
                                break;
                                }
                        return 1;
                        break;
                case 7:
                        if(skill>60){
                                return notify_fail("你的官品不夠，無法學習更高深的武技。\n");
                                return 0;
                                break;
                                }
                        return 1;
                        break;
                case 8:
                        if(skill>40){
                                return notify_fail("你的官品不夠，無法學習更高深的武技。\n");
                                return 0;
                                break;
                                }
                        return 1;
                        break;
                case 9:
                        if(skill>20){
                                return notify_fail("你的官品不夠，無法學習更高深的武技。\n");
                                return 0;
                                break;
                                }
                        return 1;
                        break;
                default:
                        write("你不是太監，無法學習此項武技。\n");
                        return 0;
                        break;
  }
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if((int)me->query("kee")<5)
                return notify_fail("你的氣不夠﹐不能練陰陽步法。\n");
        me->receive_wound("kee",5);
        return 1;
}

