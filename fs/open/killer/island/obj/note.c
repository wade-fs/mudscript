inherit ITEM;
void create ()
{
set_name("字條",({"note"}));
set_weight(10);
    if(clonep())
        set_default_object(__FILE__);
    else{
        set("long","上面寫滿了密密麻麻的東瀛文字, 看來應該拿給魯尋解讀一下!!\n");
        set("value",1);
        set("unit","個");
        setup();
}}
