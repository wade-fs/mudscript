
#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIR"紅色陸行鳥"NOR,
        ({"red land of bird","red","land","bird",}));
        set("mount_id","red-Lbird");
        set("age",12);
        set("race","野獸");
        set("score",1000000);
        set("gender","女性");
        set("level",1);
        set("rider","Lbird");
        setup();
}
string *dodge_msg = ({
HIR"$n"HIR"的紅色陸行鳥佯裝要逃走"RED"，"HIR"趁$N"HIR"不注意的"RED"，"
HIR"一個瞬間$n"HIR"已躲過$N"HIR"的攻擊"RED"。\n"NOR,
HIR"$n"HIR"往上一跳"RED"，"HIR"在此瞬間紅色陸行鳥往前衝"RED"，"HIR"攻其不意"
RED"。\n"NOR,
});
string query_dodge_msg()
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
