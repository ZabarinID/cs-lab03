#ifndef SVG_H_INCLUDED
#define SVG_H_INCLUDED

#include <vector>

using namespace std;

void
svg_begin(double width, double height) {
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg width='" << width << "' height='" << height << "' "
         << "viewBox='0 0 " << width << " " << height << "' "
         << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void
svg_end() {
    cout << "</svg>\n";
}

void svg_text(double left, double baseline, string text)
{
    cout<<"<text x='"<<left<<"' y='"<<baseline<<"'>"<<text<<"</text>";
}

void svg_rect(double x, double y, double width, double height, string stroke, string fill )
{
    cout<< "<rect x='"<<x<<"' y='"<<y<<"' width='"<<width<<"' height='"<<height<<"' stroke='"<<stroke<<"' fill='"<<fill<<"' />";
}

void
show_histogram_svg(const vector<size_t>& bins)
{
    size_t bin_max=bins[0];
    for (size_t bin: bins) // Нахожу максимальное количесвто звездочек в каждй строке
    {
        if(bin>bin_max)
        {
          bin_max=bin;
        }
    }
    const size_t MAX=80-15;
    double factor = 1.0;
    if (bin_max>MAX)
    {
        factor= static_cast<double>(MAX)/bin_max;
    }


    const auto IMAGE_WIDTH = 800;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    double top = 0;
    for (size_t bin : bins) {

            const double bin_width = bin * factor * 10;

    svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
    svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT, "black", "red");
    top += BIN_HEIGHT;
}
    svg_end();

}


#endif // SVG_H_INCLUDED
