#include <vector>
#include <cstddef>

std::vector< std::vector< std::vector<double> > > hsvToRgb(std::vector< std::vector< std::vector<double> > > m_hsvData) {
	std::size_t sx = m_hsvData.size();
	std::size_t sy = m_hsvData[0].size();
	std::vector< std::vector< std::vector<double> > > m_rgbData(m_hsvData);
	for (std::size_t x = 0; x<sx; ++x) {
		for (std::size_t y = 0; y<sy; ++y) {
			double h, s, v, f, p, q, t, r, g, b;
			assert(m_hsvData[x][y].size() == 3);
			assert(m_rgbData[x][y].size() == 3);
			h = m_hsvData[x][y][0];
			s = m_hsvData[x][y][1];
			v = m_hsvData[x][y][2];
			assert(h <= 1);
			assert(h >= 0);
			assert(s <= 1);
			assert(s >= 0);
			assert(v <= 1);
			assert(v >= 0);
			if (s == 0.0) {
				m_rgbData[x][y][0] = v;
				m_rgbData[x][y][1] = v;
				m_rgbData[x][y][2] = v;
				continue;
			}
			int i = int(h * 6);
			f = (h * 6) - i;
			p = v*(1 - s);
			q = v*(1 - s*f);
			t = v*(1 - s*(1 - f));
			i = i % 6;
			switch (i) {
			case 0: r = v, g = t, b = p; break;
			case 1: r = q, g = v, b = p; break;
			case 2: r = p, g = v, b = t; break;
			case 3: r = p, g = q, b = v; break;
			case 4: r = t, g = p, b = v; break;
			case 5: r = v, g = p, b = q; break;
			default: r = 0, g = 0, b = 0; break;
			}
			m_rgbData[x][y][0] = r;
			m_rgbData[x][y][1] = g;
			m_rgbData[x][y][2] = b;
		}
	}
	return m_rgbData;
}

int main(int argc, char** argv) {
	std::vector< std::vector< std::vector<double> > > m_hsvData(1, std::vector< std::vector<double> >(1, std::vector<double>(3, 0)));
	std::vector< std::vector< std::vector<double> > > m_rgbData = hsvToRgb(m_hsvData);
	return 0;
}

