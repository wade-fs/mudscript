
#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIB + "極速風鳳凰" + NOR,
        ({"wind-phoenix","wind","phoenix"}));
        set("mount_id","wind-phoenix");
        set("age",12);
        set("race","野獸");
        set("score",1000000);
        set("gender","女性");
set("level",1);
        set("rider","phoenix");
        setup();
}
string *dodge_msg = ({
HIW + "$n" + HIW + "的白色陸行鳥佯裝要逃走" + NOR + "，" + HIW + "趁$N" + HIW + "不注意的" + NOR + "，"
HIW + "一個瞬間$n" + HIW + "已躲過$N" + HIW + "的攻擊" + NOR + "。\n",
HIW + "$n" + HIW + "往上一跳" + NOR + "，" + HIW + "在此瞬間白色陸行鳥往前衝" + NOR + "，" + HIW
"攻其不意" + NOR + "。\n",
});
string query_dodge_msg()
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
