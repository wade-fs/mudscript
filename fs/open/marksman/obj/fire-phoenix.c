
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("極燄火鳳凰",
        ({"fire-phoenix","fire","phoenix",}));
        set("mount_id","fire-phoenix");
        set("age",12);
        set("race","野獸");
        set("score",1000000);
        set("gender","女性");
set("level",1);
        set("rider","phoenix");
        setup();
}
string *dodge_msg = ({
"$n的黑色陸行鳥佯裝要逃走，趁$N不注意的"
"，一個瞬間$n已躲過$N的攻擊。\n",
"$n往上一跳，在此瞬間黑色陸行鳥往前衝，"
"攻其不意。\n",
});
string query_dodge_msg()
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
