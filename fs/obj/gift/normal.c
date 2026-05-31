
#include <ansi.h>

string give_gift();

private mixed *story = ({
        "江湖風平浪靜，波瀾不驚。",
});

void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}
