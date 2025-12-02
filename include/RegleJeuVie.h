#if !defined(DEF_REGLE_JEU_VIE)
#define DEF_REGLE_JEU_VIE

#include <Regle.h>

class RegleJeuVie :public Regle
{
public:
    RegleJeuVie();
    ~RegleJeuVie();
    bool respecte() override;
};







#endif // DEF_REGLE_JEU_VIE