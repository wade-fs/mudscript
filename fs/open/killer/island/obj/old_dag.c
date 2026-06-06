inherit ITEM;
void create ()
{
set_name("生鏽的舊匕首",({"old dagger","dagger"}));
set_weight(10);
    if(clonep())
        set_default_object(__FILE__);
    else{
        set("long","一把生鏽的舊匕首, 似乎是魯仝以前所使用的東西, 還是將他交還給他吧!!\n");
        set("value",1);
        set("unit","把");
        setup();
}}
