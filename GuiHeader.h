#ifdef GUIDLL_EXPORTS
#define GUIDLL_API __declspec(dllexport)
#else
#define GUIDLL_API __declspec(dllimport)
#endif

namespace GUI {
	class Interactions {
	public:
		static GUIDLL_API int GetToTheChoppa();

		static GUIDLL_API void SqSize(int size, int face_height);

		static GUIDLL_API void FirstColor(int Rval, int Gval, int Bval);

		static GUIDLL_API void SecondColor(int Rval, int Gval, int Bval);

		static GUIDLL_API void Gradient(int True);
	};
}