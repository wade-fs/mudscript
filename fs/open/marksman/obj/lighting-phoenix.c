
#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIG + "極殺雷鳳凰" + NOR,
        ({"lighting-phoenix","lighting","phoenix",}));
        set("mount_id","lighting-phoenix");
        set("age",12);
        set("race","野獸");
        set("score",1000000);
        set("gender","女性");
set("level",1);
        set("rider","phoenix");
        setup();
}
string *dodge_msg = ({
HIG + "$n" + HIG + "的綠色陸行鳥佯裝要逃走" + GRN + "，" + HIG + "趁$N" + HIG + "不注意的" + GRN + "，"
HIG + "一個瞬間$n" + HIG + "已躲過$N" + HIG + "的攻擊" + GRN + "。\n" + NOR,
HIG + "$n" + HIG + "往上一跳" + GRN + "，" + HIG + "在此瞬間白色陸行鳥往前衝" + GRN + "，" + HIG + "攻其不意" + GRN + "。\n" + NOR,
});
string query_dodge_msg()
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
