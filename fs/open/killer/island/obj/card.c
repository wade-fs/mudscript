inherit ITEM;
void create ()
{
set_name("令牌",({"card"}));
set_weight(10);
    if(clonep())
        set_default_object(__FILE__);
    else{
        set("long","
令牌上多鑲了幾塊小石子, 還用紅繩子穿起來, 猜測似乎是魯仝給麗子的定情之物....
雖然看起來好笑,但也看得出來魯仝的用情之深....
這就是魯先生的夢想了嗎......??冒險探索的目的只是為了這些珠寶嗎??
我覺得還是將這塊令牌放回盒子裡讓夢想在這陪伴麗子吧!!
\n");
        set("value",1);
        set("unit","張");
        setup();
}}
