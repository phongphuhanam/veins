//
// Copyright (C) 2018 Fabian Bronner <fabian.bronner@ccs-labs.org>
//
// Documentation for these modules is at http://veins.car2x.org/
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

#ifndef SPECTRUM_H_
#define SPECTRUM_H_

#include <stdint.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <memory>
#include <fstream>
#include <assert.h>
#include <map>

namespace Veins {

typedef std::vector<double> Freqs;

class Spectrum {
public:
    Spectrum() = default;
    Spectrum(Freqs freqs);

    const double& operator[](size_t index) const;

    size_t getNumFreqs() const;

    size_t indexOf(double freq) const;
    size_t indexNearLow(double freq) const;
    size_t indexNearUp(double freq) const;

    double freqAt(size_t freqIndex) const;

    void print() const;
    void toFile(std::string path) const;

    friend bool operator==(const Spectrum& lhs, const Spectrum& rhs);

private:
    Freqs frequencies;
};

} // namespace Veins

#endif /* SPECTRUM_H_ */
