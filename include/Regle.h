#if !defined(DEF_REGLE)
#define DEF_REGLE


class Regle
{
public:
    ~Regle();
    virtual bool respecte() =0;
};






#endif // DEF_REGLE