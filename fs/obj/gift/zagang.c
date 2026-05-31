// story:zagang.c

#include <ansi.h>

string give_gift();

private mixed *story = ({
        "不好啦～～～不好啦～～～",
        "司馬光：怎麼了？出什麼事了？",
        "小孩甲：死不了掉到缸裡了。",
        "司馬光咳嗽一聲，道：我還以為什麼大不了的事，他不是死不了嘛！慌甚麼。",
        "眾小孩亂成一團。",
        "冰～～糖～～葫～～蘆～～",
        "司馬光驀然而起：他奶奶的，我記得死不了還欠我一串糖葫蘆！",
        "小孩乙：是有這麼回事，不過你要不馬上找到家長把死不了撈上來，就別指望了！",
        "哼！司馬光冷冷笑道：區區小事，何足掛齒？",
        "......",
        "司馬光舉起一塊石頭，狠狠的砸了下去，「匡當」，缸破水出。",
        "死不了苟延殘喘。",
        "司馬光翻起死不了，道：死不了啊死不了，你欠我的那串冰糖葫蘆還記不記得？",
        "死不了：你說啥？",
        "乒乓！",
        "死不了被司馬光扔到了缸裡。",
        "死不了從缸裡扔出了一串冰糖葫蘆。",
        (: give_gift :)
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
        STORY_D->give_gift("/obj/gift/bingtang", 1,
                           HIM "\n「啪」的一聲一棵冰糖葫蘆掉到你面前。\n\n" NOR);
        return 0;
}
