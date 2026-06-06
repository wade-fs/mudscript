#include <weapon.h>
  inherit ITEM;
void create()
{
set_name("魔 血",({"blood"}));
set("unit","灘");
set("long","這灘奇怪的血漬竟被一道道奇怪的符咒包圍...你可以試著解開它

      (tear taoistfigure)
\n");
  set("no_get",1);
        setup();
}
