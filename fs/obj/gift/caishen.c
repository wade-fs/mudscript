// story:caishen 財神

#include <ansi.h>

int give_gift(string money, int amount, string name);

private mixed *story = ({
        "大小財神狹路相逢。",
        "大財神：讓路！",
        "小財神：憑什麼？",
        "大財神：廢話，憑我比你有錢。",
        "小財神摸出幾個銅板，隨手扔了出去，哼哼道：來！",
        (: give_gift, "coin", 20 + random(100), "銅板" :),
        "大財神一聲冷笑，摸出一些白銀扔了出去。",
        (: give_gift, "silver", 20 + random(30), "白銀" :),
        "小財神摸了半天，掏出一些黃金，咬咬牙扔了出去，道：繼續呀！",
        (: give_gift, "gold", 10 + random(30), "黃金" :),
        "大財神面如土色，道：您老有錢，您老有錢，我讓路，我讓路。",
});

void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

int give_gift(string money, int amount, string name)
{
        STORY_D->give_gift("/obj/money/" + money, amount,
                           HIM + "\n「啪」的一聲一些" + name + "掉到你面前。\n\n" + NOR);
        return 1;
}
