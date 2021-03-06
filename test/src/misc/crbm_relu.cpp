//=======================================================================
// Copyright (c) 2014-2017 Baptiste Wicht
// Distributed under the terms of the MIT License.
// (See accompanying file LICENSE or copy at
//  http://opensource.org/licenses/MIT)
//=======================================================================

#include <numeric>

#include "catch.hpp"

#include "dll/rbm/conv_rbm.hpp"

#include "mnist/mnist_reader.hpp"
#include "mnist/mnist_utils.hpp"

TEST_CASE("crbm/mnist_7", "crbm::relu") {
    dll::conv_rbm_square_desc<
        1, 28, 40, 17,
        dll::batch_size<25>,
        dll::hidden<dll::unit_type::RELU>>::layer_t rbm;

    rbm.learning_rate *= 2;

    auto dataset = mnist::read_dataset_direct<std::vector, etl::fast_dyn_matrix<float, 1, 28, 28>>(100);
    REQUIRE(!dataset.training_images.empty());

    mnist::binarize_dataset(dataset);

    auto error = rbm.train(dataset.training_images, 100);

    REQUIRE(error < 1e-2);
}

TEST_CASE("crbm/mnist_8", "crbm::relu6") {
    dll::conv_rbm_square_desc<
        1, 28, 40, 17,
        dll::batch_size<25>,
        dll::hidden<dll::unit_type::RELU6>>::layer_t rbm;

    rbm.learning_rate *= 2;

    auto dataset = mnist::read_dataset_direct<std::vector, etl::fast_dyn_matrix<float, 1, 28, 28>>(100);
    REQUIRE(!dataset.training_images.empty());

    mnist::binarize_dataset(dataset);

    auto error = rbm.train(dataset.training_images, 100);

    REQUIRE(error < 5e-3);
}

TEST_CASE("crbm/mnist_9", "crbm::relu1") {
    dll::conv_rbm_square_desc<
        1, 28, 40, 17,
        dll::batch_size<25>,
        dll::hidden<dll::unit_type::RELU1>>::layer_t rbm;

    rbm.learning_rate *= 2;

    auto dataset = mnist::read_dataset_direct<std::vector, etl::fast_dyn_matrix<float, 1, 28, 28>>(100);
    REQUIRE(!dataset.training_images.empty());

    mnist::binarize_dataset(dataset);

    auto error = rbm.train(dataset.training_images, 100);

    REQUIRE(error < 5e-2);
}
