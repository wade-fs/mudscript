// story:food_god.c

#include <ansi.h>

string give_gift();

private mixed *story = ({
    "太白金星：唉！肚子好餓阿，食神阿，你有沒有東西可以給我吃阿？",
    "食神：真是不巧，廚房裡面的東西都被鬥戰勝佛拿去吃了，只剩下一顆雞蛋。",
    "太白金星：雞蛋有啥好吃的阿？？？",
    "食神：開玩笑，我可是食神耶，看我的，喝～～～",
    "太白金星：哇！少林絕學！火～～雲～～掌！！！",
    "轉眼間，生雞蛋已經變成了一片香噴噴的荷包蛋。",
    "忽然間，食神的手一陣抽筋，已經煎好的荷包蛋也跟著往下掉。",
    (: give_gift :),
    "食神：哎呀！我忘記這招只能在剛上完廁所才可以使用．．．",
    "太白金星：．．．．．．",
});

void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

string give_gift()
{
        STORY_D->give_gift("/obj/gift/hobowdan", 1,
                           HIM + "\n「啪」的一聲一片香噴噴的荷包蛋掉在你面前。\n\n" + NOR);
        return "太白金星急道：啊～～我的蛋蛋！！";
}
