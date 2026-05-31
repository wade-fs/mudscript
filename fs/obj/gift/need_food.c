// story:food_god.c

#include <ansi.h>

string give_gift();

private mixed *story = ({
    "一年一度土地公誕辰日，指南宮外有信徒舉辦謝神活動",
"台上的女郎賣力跳舞，衣服也一件一件的脫掉，",
"土地公看的目不轉睛，沒注意到土地婆已經氣沖沖走了過來，",
"土地婆一把捉住土地公的耳朵，土地公痛的哇哇大叫",
"土地婆:你這老不休，都一把年紀了，還在看年輕妹妹脫衣舞!",
"土地公:唉喲，老婆，這是信徒請來的給我看的，可不是我主動要求的!",
"土地婆:那你可以不看呀，還是你嫌老娘身材不夠好，要看別的女人呀",
"土地公:老婆妳別誤會了，我沒有這意思，我沒有嫌妳身材不夠好",
"土地婆:哼，不是我不夠好，是別人比較好摟!",
"土地婆說罷，用力一捏，土地公痛到把手上的貢品掉下去了!",
(: give_gift:)
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
        STORY_D->give_gift("/obj/gift/kardan", 1,
                           HIM "\n貢品滾啊滾啊滾到你的腳邊。\n\n" NOR);
        return "土地公說道：哎呀，這些都是信徒給我的貢品啊啊啊啊。";
}
