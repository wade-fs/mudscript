#include <weapon.h>
 inherit ITEM;

void create()
{
    set_name("黃金甲龍",({"stone golden dragon" ,"dragon",}));

   set("unit","隻");
  set("no_sac",1);
set("long","\n已經焉焉一息的傳說中神獸 ,你可以用內力
扯斷鐵銬放它自由(free dragon) ,但後果沒人敢說!!\n\n");
  set("no_get",1);                    
        setup();
}

