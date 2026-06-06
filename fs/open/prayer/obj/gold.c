//黃金()
#include <command.h>
inherit ITEM;

void create()
{
        set_name("金子", ({ "golden" }));
        set_weight(30000);
        if( clonep() )
          set_default_object(__FILE__);
        else
        {
          set("unit", "塊");
          set("long",@LONG
	這是一塊黃澄澄的黃金!!純度可能有 9999 吧!!你可以將它
        拿去給冶鑄的工匠, 金子做成武器或是防具都是不錯的!!雖
	然密度高, 安定性佳, 可是硬度差, 延展性佳, 做為武器的
	基材會使得武器的壽命減短許多!!
LONG);
          set("value", 800);
          set("material", "gold");
          set("no_sell", 1);
          set("no_auc", 1);
        }
}


