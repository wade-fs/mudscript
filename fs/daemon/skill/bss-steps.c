//絳雪步法 by bss
#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({

        "\n只見$n躍至空中，忽地一閃，消失了身影，竟然是失傳已久的輕功\絕技 " + HIY + "「凌空逝影」" + NOR + "，使得$N的攻擊完全無效。\n",

        "\n$n的腳下忽然加快，左右晃動下，居然出現了七個你的身影，正是忍術中的" + HIB + "「忍者七分身法」" + NOR + "\n，$N在震驚之餘，完全分不出那一個是真的$n。\n",

        "\n$n腳踩八卦，忽左忽右地繞到了對手的身後，正是" + HIG + "「八卦遊龍步法」" + NOR + "中的精華" + HIC + "「扭轉乾坤」" + NOR + "，面對這突如其來的舉動，使得$N完全無法招架。\n",

"\n忽然$n眼放精光，大喝一聲" + HIR + "「幻魔身法」" + NOR + "，身形展開$n就像一縷\輕煙般從$N眼前消失，使得\n$N失去了攻擊目標。\n",

        "\n$n運起" + HIB + "忘" + HIW + "情" + HIY + "天" + HIR + "書" + NOR + "中的絕技" + HIC + "「天意」" + NOR + "，天意一出，人如天意，天意不可奪，面對這強大的招式，使$N收回所有的攻擊。\n",

        "\n$n運起" + HIB + "忘" + HIW + "情" + HIY + "天" + HIR + "書" + NOR + "中的絕技" + HIM + "「木頑」" + NOR + "，$n的身體忽然變得跟朽木一般，使得$N得招式完全失去了效用。\n",

        "\n$n運起" + HIB + "忘" + HIW + "情" + HIY + "天" + HIR + "書" + NOR + "中的絕技" + HIG + "「地勢」" + NOR + "，$n的身形忽高忽低，隨著地勢的起伏而移動，$N被地勢所阻，無法進攻。\n",

        "\n$n運起" + HIB + "忘" + HIW + "情" + HIY + "天" + HIR + "書" + NOR + "中的絕技" + HIY + "「君王」" + NOR + "，氣勢有如君王駕到，銳不可檔，使$N完全不敢對$n攻擊。\n",

        "\n$n運起" + HIB + "忘" + HIW + "情" + HIY + "天" + HIR + "書" + NOR + "中的絕技" + HIB + "「水逝」" + NOR + "，身形有如流水般挪移到了一旁，使得$N招式落空了。\n",

        "\n$n運起" + HIB + "忘" + HIW + "情" + HIY + "天" + HIR + "書" + NOR + "中的絕技" + HIR + "「風流」" + NOR + "，身形急旋，因旋轉造成的氣流在$n身旁形成一道氣牆，將$N的招式完全阻隔了。\n",

        "\n$n運起" + HIB + "忘" + HIW + "情" + HIY + "天" + HIR + "書" + NOR + "中的絕技" + MAG + "「我無」" + NOR + "，我即是無，無即是我，$n就像忽然間不見了一般消失在$N的眼前。\n",

});



int valid_enable(string usage) {
        return (usage=="dodge")||(usage=="move");

}

int valid_learn(object me)
{
        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if((int)me->query("kee")<5)
                return notify_fail("你的氣不夠﹐不能練絳雪步法。\n");
        me->receive_wound("kee",5);
        return 1;
}


