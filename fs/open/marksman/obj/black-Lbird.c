
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("黑色陸行鳥",
        ({"black land of bird","black","land","bird",}));
        set("mount_id","black-Lbird");
        set("age",12);
        set("race","野獸");
        set("score",1000000);
        set("gender","女性");
        set("level",1);
        set("rider","Lbird");
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
