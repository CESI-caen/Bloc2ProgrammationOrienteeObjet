#if !defined(DEF_REGLE)
#define DEF_REGLE


class Regle
{
public:
    virtual ~Regle() =default;
    virtual void afficherRegle() =0;
};

#endif // DEF_REGLE