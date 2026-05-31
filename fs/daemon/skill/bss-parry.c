
#include <ansi.h>
inherit SKILL;

string *parry_msg =
({

        "\n$n運起"HIB"忘"HIW"情"HIY"天"HIR"書"NOR"中的絕技"HIC"「天意」"NOR"，天意一出，人如天意，天意不可奪，面對這強大的招式，使$N收回所有的攻擊。\n",

        "\n$n運起"HIB"忘"HIW"情"HIY"天"HIR"書"NOR"中的絕技"HIM"「木頑」"NOR"，$n的身體忽然變得跟朽木一般，使得$N得招式完全失去了效用。\n",

        "\n$n運起"HIB"忘"HIW"情"HIY"天"HIR"書"NOR"中的絕技"HIG"「云翳」"NOR"，招式所產生的風雲氣流阻擋住了$N，使$N的攻擊失去效用\n",

        "\n$n運起"HIB"忘"HIW"情"HIY"天"HIR"書"NOR"中的絕技"HIY"「君王」"NOR"，氣勢有如君王駕到，銳不可檔，使$N完全不敢對$n攻擊。\n",

        "\n$n運起"HIB"忘"HIW"情"HIY"天"HIR"書"NOR"中的絕技"HIB"「土掩」"NOR"，$n將腳下泥土以內力揚起，塵土夾帶的真氣將$N阻擋，使得$N招式落空了。\n",

        "\n$n運起"HIB"忘"HIW"情"HIY"天"HIR"書"NOR"中的絕技"HIR"「風流」"NOR"，身形急旋，因旋轉造成的氣流在$n身旁形成一道氣牆，將$N的招式完全阻隔了。\n",

        "\n$n運起"HIB"忘"HIW"情"HIY"天"HIR"書"NOR"中的絕技"MAG"「我無」"NOR"，我即是無，無即是我，$n就像忽然間不見了一般消失在$N的眼前。\n",

});

int valid_enable(string usage) {
        return (usage=="parry");

}

string query_parry_msg(string limb){

        return parry_msg[random(sizeof(parry_msg))];
}

int valid_learn(object me)
{
        return 1;
}
